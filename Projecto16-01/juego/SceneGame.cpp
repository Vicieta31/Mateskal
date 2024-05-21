#include "SceneGame.h"

SceneGame::SceneGame()
{
	backgroundImage = NULL;
}

SceneGame::~SceneGame()
{
	// Limpiar memoria al finalizar
	for (auto& enemy : enemies) {
		delete enemy;
	}
	enemies.clear();
}

void SceneGame::init()
{
	direccion = 0;
	dispDireccion = 0;

	ResourceManager::getInstance()->printLoadedGraphics();

	cambioNivel.Init();
	character.Init();

	// Crear enemigos y a�adirlos al vector
	if (enemies.size() <= 5)
	{
		for (int i = 0; i < 5; ++i) {
			enemies.push_back(Enemy::CreateEnemy());
		}
	}

	backgroundImage = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Pantalla1.jpg");
	MyMap.loadMap("TestResources/miMapa1tmx.tmx");
}

void SceneGame::update()
{
	InputManager::getInstance()->Update();

	direccion = InputManager::getInstance()->GetDirection();

	dispDireccion = InputManager::getInstance()->GetShot();

	character.Update(direccion, dispDireccion);

	int jX = character.GetPosX();
	int jY = character.GetPosY();
	std::cout << jX << std::endl;

	MyMap.setCameraPosition(jX, jY);


	if (cambioNivel.CheckCharacterCollisionL(character))// Devuelve true o false
	{
		character.RePosX();
		character.RetPosY();
		SceneDirector::getInstance()->changeScene(MainMenu);
	} 
	/*
	for (auto& enemy : enemies) {
		enemy->Update(character.GetPosX(), character.GetPosY());
		character.CheckBulletCollision(*enemy);
		enemy->CheckCharacterCollisionE(character);
	}
	// Eliminar enemigos muertos
	enemies.erase(remove_if(enemies.begin(), enemies.end(), [](Enemy* enemy) {
		if (enemy->GetHealth() <= 0) {
			delete enemy;
			return true;
		}
	return false;
		}), enemies.end());
		*/
}

void SceneGame::render()
{
	// Background render
	VideoManager::getInstance()->renderGraphic(backgroundImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	MyMap.render();

	// Clases propias render
	cambioNivel.Render();
	character.Render();
	/*
	for (auto& enemy : enemies) {
		enemy->Render();
	}
	*/
	VideoManager::getInstance()->updateScreen();
}
