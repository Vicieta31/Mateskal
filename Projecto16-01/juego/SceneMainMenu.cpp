#include "SceneMainMenu.h"

SceneMainMenu::SceneMainMenu()
{
	backgroundImage = NULL;
	option = 0;
}

SceneMainMenu::~SceneMainMenu()
{
}

void SceneMainMenu::init()
{
	backgroundImage = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Bliss.png");
	mReinit = false;
}

void SceneMainMenu::update()
{
	int dir = InputManager::getInstance()->GetDirection();
	if (dir == dLEFT)
	{
		if (option > 0)
		{
			option--;
		}
	}
	if (dir == dRIGHT)
	{
		if (option < 3)
		{
			option++;
		}
	}
}

void SceneMainMenu::render()
{
	std::cout << option << "\n";
	VideoManager::getInstance()->renderGraphic(backgroundImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
