#include "SceneDirector.h"

SceneDirector* SceneDirector::pInstance = NULL; 

SceneDirector::SceneDirector()
{
	_placeHolder = 0;
	scene = MainMenu;
}
SceneDirector::~SceneDirector()
{
}

void SceneDirector::init() {
	mVectorScene.resize(NUM_SCENES);

}

void SceneDirector::ChangeScene(sceNum nextScene, bool reinit = true)
{
	mVectorScene[nextScene]->setReInit(reinit);
	mCurrentScene = nextScene;


	// Se va a ir a la basura esto jaj
	if (_placeHolder == 1)
	{
		scene = MainMenu;
	}
	if (_placeHolder == 3)
	{
		if (scene == MainMenu)
		{
			scene = GameLevels;
		}
	}
	if (_placeHolder == 5)
	{
		if (scene == MainMenu)
		{
			scene = HighScores;
		}
	}
}
