#include "SceneGame.h"

SceneGame::SceneGame()
{
	backgroundImage = NULL;
}

SceneGame::~SceneGame()
{
}

void SceneGame::init()
{
	backgroundImage = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Pantalla1.jpg");
}

void SceneGame::update()
{
}

void SceneGame::render()
{
	VideoManager::getInstance()->renderGraphic(backgroundImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
