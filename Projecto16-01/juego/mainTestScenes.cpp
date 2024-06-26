#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "SoundManager.h"
#include <string>

#include <cmath>
#include <stdlib.h>
#include <time.h>

#include <iostream>

using namespace std;

Uint32 global_elapsed_time = 0;
bool playing = true;
SceneDirector* sDirector = NULL;
SoundManager* sManager = NULL;
InputManager* kManager = NULL;
ResourceManager* rManager = NULL;

int main(int argc, char* args[]) 
{
	srand(time(NULL));
	// INIT todos los manager directors
	VideoManager::getInstance();
	sDirector = SceneDirector::getInstance();
	sManager = SoundManager::getInstance();
	kManager = InputManager::getInstance();
	rManager = ResourceManager::getInstance();

	SoundManager::getInstance()->PlaySound("Sounds/backMu.mp3", true);

	while (playing == true)
	{
		if (sDirector->getCurrentScene()->mustReInit()) {
			sDirector->getCurrentScene()->init();
		}

		// Updates scene
		kManager->Update();
		sDirector->getCurrentScene()->update();
		if (kManager->GetPause())
		{
			playing = false;
		}

		sDirector->getCurrentScene()->render();
		VideoManager::getInstance()->updateScreen();
	}
	 
	return 0;
}