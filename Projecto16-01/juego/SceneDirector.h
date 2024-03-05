#pragma once
#include <SDL.h>
#include "InputManager.h"

enum scene { MainMenu, GameLevels, HighScores };

class SceneDirector
{
private:
	int scene;
	int _placeHolder;

	/*
		Cosas para cambiar la escena jej
	*/
	void ChangeScene();

	static SceneDirector* pInstance;

	
public:
	~SceneDirector();

	void Update(int placeHolder);

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
};

