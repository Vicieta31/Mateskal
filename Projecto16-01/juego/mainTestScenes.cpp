#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include <iostream>

using namespace std;

int main(int argc, char* args[]) 
{
	int direccion = 0;
	int escena = MainMenu;

	VideoManager::getInstance();

	SceneDirector::getInstance();

	while (true)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();

		//SceneDirector::getInstance()->ChangeScene();
		escena = SceneDirector::getInstance()->GetScene();
		//cout << direccion;

		//los siguientes if se cambiaran dentro de SceneDirector dependiendo de como se cambie de escena
		
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