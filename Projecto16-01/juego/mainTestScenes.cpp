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
	bool contrue = false;
	while (contrue == false)
	{
		InputManager::getInstance()->Update();

		direccion = InputManager::getInstance()->GetDirection();

		SceneDirector::getInstance()->Update(direccion);
		escena = SceneDirector::getInstance()->GetScene();
		contrue = InputManager::getInstance()->GetPause();
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