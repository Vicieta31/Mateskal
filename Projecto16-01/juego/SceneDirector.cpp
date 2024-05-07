#include "SceneDirector.h"

SceneDirector* SceneDirector::pInstance = NULL; 

SceneDirector::SceneDirector()
{
	_placeHolder = 0;
	actScene = MainMenu;
}
SceneDirector::~SceneDirector()
{
}

void SceneDirector::ChangeScene()
{
	if (_placeHolder == 1)
	{
		actScene = MainMenu;
	}
	if (_placeHolder == 3)
	{
		if (actScene == MainMenu)
		{
			actScene = GameLevels;
		}
	}
	if (_placeHolder == 5)
	{
		if (actScene == MainMenu)
		{
			actScene = HighScores;
		}
	}
}

void SceneDirector::Update(int placeHolder)
{
	_placeHolder = placeHolder;

	ChangeScene();
}
