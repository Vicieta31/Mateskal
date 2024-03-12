#pragma once
#include <SDL.h>
#include "InputManager.h"

#include <vector>
#include "Scene.h"

enum sceNum { MainMenu, GameLevels, HighScores, _LASTSCENE };

#define NUM_SCENES _LASTSCENE

class SceneDirector
{
private:
	int scene;
	int _placeHolder;

	/*
		Cosas para cambiar la escena jej
	*/
	
public:
	~SceneDirector();

	void init();

	void ChangeScene(sceNum nextScene, bool reinit = true);

	/*
		Returns actual Scene
	*/
	int GetScene() { return scene; };

	/*
		\return Instance of SceneDirector (Singleton).
	*/
	static SceneDirector* getInstance() 
	{
		if (pInstance == NULL) {
			pInstance = new SceneDirector();
		}

		return pInstance;
	};
protected:
	SceneDirector();
	static SceneDirector* pInstance;

	std::vector<Scene*>	mVectorScene;
	sceNum mCurrentScene;
};

