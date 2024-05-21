#include "SceneGame.h"

SceneGame::SceneGame()
{
	backgroundImage = NULL;
}

SceneGame::~SceneGame()
{
	// Limpiar memoria al finalizar
	for (int i = 0; i < enemies.size(); ++i) {
		const Enemy& enemy = *enemies[i];
		delete enemies[i];
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
		SoundManager::getInstance()->PlaySound("Sounds/end.mp3", false);
		character.RePosX();
		character.RetPosY();
		character.RetHp();
		SceneDirector::getInstance()->changeScene(MainMenu);
	} 
	if (!character.GetLive())
	{
		SoundManager::getInstance()->PlaySound("Sounds/lose.mp3", false);
		character.RePosX();
		character.RetPosY();
		character.RetHp();
		SceneDirector::getInstance()->changeScene(MainMenu);
	}

	
	for (int i = 0; i < enemies.size(); ++i) {
		const Enemy& enemy = *enemies[i];
		enemies[i]->Update(character.GetPosX(), character.GetPosY());
		character.CheckBulletCollision(*enemies[i]);
		enemies[i]->CheckCharacterCollisionE(character);
	}
	// Eliminar enemigos muertos
	enemies.erase(remove_if(enemies.begin(), enemies.end(), [](Enemy* enemy) {
		if (enemy->GetHealth() <= 0) {
			delete enemy;
			return true;
		}
	return false;
		}), enemies.end());
		
}

void SceneGame::render()
{
	// Background render
	VideoManager::getInstance()->renderGraphic(backgroundImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	MyMap.render();

	// Clases propias render
	cambioNivel.Render();
	character.Render();

	for (int i = 0; i < enemies.size(); ++i) {
		const Enemy& enemy = *enemies[i];
			enemies[i]->Render();
	}
	
	VideoManager::getInstance()->updateScreen();
}
