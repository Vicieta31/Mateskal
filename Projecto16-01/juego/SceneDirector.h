#pragma once
#include <SDL.h>
#include <vector>

#include "InputManager.h"
#include "BaseScene.h"

//! Enum scenes.
/*! All the Scenes in game. */
// Main menu, nivel, puntuaciones
enum scene { MainMenu, GameLevels, HighScores, _LastScene };

#define NUM_SCENES _LastScene

class SceneDirector
{
public:
	~SceneDirector();

	void init();

	void changeScene(scene nextScene, bool reinit = true);

	scene getCurrentSceneEnum() { return actScene; };

	// escena base get curren scene
	BaseScene* getCurrentScene() { return mVectorScenes[actScene]; };

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
	std::vector<BaseScene*>	mVectorScenes;

	static SceneDirector* pInstance;

private:
	int _placeHolder;
		
};

