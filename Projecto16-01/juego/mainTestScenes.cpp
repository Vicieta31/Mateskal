#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include <iostream>

using namespace std;
enum scene {MainMenu, GameLevels, HighScores};

int main(int argc, char* args[]) 
{
	int direccion = 0;
	int disp = 0;
	int escena = MainMenu;

	VideoManager::getInstance();

	while (true)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();
		//cout << direccion;
		
		disp = InputManager::getInstance()->GetShot();
		//cout << disp;

		//los siguientes if se cambiaran dentro de SceneDirector dependiendo de como se cambie de escena
		if (direccion == 1)
		{
			escena = MainMenu;
		}
		if (direccion == 3)
		{
			if (escena == MainMenu)
			{
				escena = GameLevels;	
			}
		}
		if (direccion == 5)
		{
			if (escena == MainMenu)
			{
				escena = HighScores;
			}
		}
		if (escena == MainMenu)
		{
			cout << "MainMenu" << endl;
		}
		if (escena == GameLevels)
		{
			cout << "GameLevels" << endl;
		}
		if (escena == HighScores)
		{
			cout << "HighScores" << endl;
		}
	}
	 
	return 0;
}