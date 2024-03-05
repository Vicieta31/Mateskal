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

void SceneDirector::ChangeScene()
{
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

void SceneDirector::Update(int placeHolder)
{
	_placeHolder = placeHolder;

	ChangeScene();
}
