#pragma once
#include <SDL.h>
#include <vector>

#include "InputManager.h"

//! Enum scenes.
/*! All the Scenes in game. */
// Main menu, nivel, puntuaciones
enum scene { MainMenu, GameLevels, HighScores };

class SceneDirector
{
public:
	~SceneDirector();

	void init();

	void changeScene(scene nextScene, bool reinit = true);

	scene getCurrentSceneEnum() { return actScene; };

	// escena base get curren scene

	void Update(int placeHolder);

	/*
		Returns actual Scene
	*/
	int GetScene() { return actScene; };

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
	scene actScene;
	static SceneDirector* pInstance;

private:
	int _placeHolder;

	/*
		Cosas para cambiar la escena jej
	*/
	void ChangeScene();


	
};

