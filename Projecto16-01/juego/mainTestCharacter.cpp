#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

#include "Character.h"
#include "Enemy.h"

#include <iostream>

using namespace std;

int main(int argc, char* args[]) 
{
	
	int direccion = 0;
	int disp = 0;

	int Pantalla1 = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Pantalla1.jpg", 1);

	ResourceManager::getInstance()->printLoadedGraphics();

	Character character;
	Enemy enemy;

	character.Init();
	enemy.Init();

	while (true)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();
		cout << direccion;

		disp = InputManager::getInstance()->GetShot();
		cout << disp;

		character.Update(direccion, disp);
		enemy.Update(character.GetPosX(), character.GetPosY()); // Pasa posicion character ha enemy

		VideoManager::getInstance()->renderGraphic(Pantalla1, 0, 0, 1080, 720);

		character.Render();
		enemy.Render();

		VideoManager::getInstance()->updateScreen();
	}
	
	return 0;
}