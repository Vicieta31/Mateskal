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

	bool enter = InputManager::getInstance()->GetEnter();

	if (enter == true)
	{
		if (option == 0)
		{
			std::cout << "Escena " << option << "\n";
			SceneDirector::getInstance()->changeScene(GameLevels);
		}
		if (option == 1)
		{
			std::cout << "Escena " << option << "\n";
		}
		if (option == 2)
		{
			std::cout << "Exit " << option << "\n";
			InputManager::getInstance()->SetPause();
		}
	}

	if (dir == dLEFT)
	{
		option = 0;
	}
	if (dir == dRIGHT)
	{
		option = 1;
	}
	if (dir == dUP)
	{
		option = 2;
	}

}

void SceneMainMenu::render()
{
	std::cout << option << "\n";
	VideoManager::getInstance()->renderGraphic(backgroundImage, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}
