#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>

using namespace std;

int main(int argc, char* args[]) 
{
	
	int direccion = 0;
	int disp = 0;

	ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/Bliss.png", 1);

	int Two = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/nada.jpg", 1);

	ResourceManager::getInstance()->removeGraphic("TestResources/Bliss.png");

	int Tres = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg", 1);

	ResourceManager::getInstance()->setAlphaGraphic(Tres, 128);

	ResourceManager::getInstance()->printLoadedGraphics();

	while (true)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();
		//cout << direccion;
		
		disp = InputManager::getInstance()->GetShot();
		cout << disp;

		/*
		VideoManager::getInstance()->renderGraphic(Two, 0, 0, 1080, 720);

		VideoManager::getInstance()->updateScreen();

		VideoManager::getInstance()->waitTime(1000);

		VideoManager::getInstance()->renderGraphic(Tres, 0, 0, 1080, 720);

		VideoManager::getInstance()->updateScreen();

		VideoManager::getInstance()->waitTime(100);
		*/
	}
	 
	return 0;
}