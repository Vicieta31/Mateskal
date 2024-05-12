#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "Character.h"
#include "Enemy.h"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char* args[])
{
	srand(time(NULL));
	int direccion = 0;
	int disp = 0;

	int Pantalla1 = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Pantalla1.jpg", 1);

	ResourceManager::getInstance()->printLoadedGraphics();

	Character character;
	character.Init();

	vector<Enemy*> enemies; // Vector dinámico de enemigos

	// Crear enemigos y añadirlos al vector
	for (int i = 0; i < 5; ++i) {
		enemies.push_back(Enemy::CreateEnemy());
	}

	while (true)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();
		cout << direccion;

		disp = InputManager::getInstance()->GetShot();
		cout << disp;

		character.Update(direccion, disp);

		// Actualizar cada enemigo
		for (auto& enemy : enemies) {
			enemy->Update(character.GetPosX(), character.GetPosY());
			character.CheckBulletCollision(*enemy);
			enemy->CheckCharacterCollision(character);
		}

		// Eliminar enemigos muertos
		enemies.erase(remove_if(enemies.begin(), enemies.end(), [](Enemy* enemy) {
			if (enemy->GetHealth() <= 0) {
				delete enemy;
				return true;
			}
			return false;
			}), enemies.end());

		VideoManager::getInstance()->renderGraphic(Pantalla1, 0, 0, 1080, 720);

		character.Render();
		for (auto& enemy : enemies) {
			enemy->Render();
		}

		VideoManager::getInstance()->updateScreen();
	}

	// Limpiar memoria al finalizar
	for (auto& enemy : enemies) {
		delete enemy;
	}
	enemies.clear();

	return 0;
}