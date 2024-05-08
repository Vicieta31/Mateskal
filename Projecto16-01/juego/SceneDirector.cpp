#include "SceneDirector.h"
#include "SceneMainMenu.h"
#include <iostream>

SceneDirector* SceneDirector::pInstance = NULL; 

SceneDirector::SceneDirector()
{
	_placeHolder = 0;
	actScene = MainMenu;
	init();
}
SceneDirector::~SceneDirector()
{
}

void SceneDirector::init()
{
	mVectorScenes.resize(NUM_SCENES);

	SceneMainMenu* mainS = new SceneMainMenu();

	mVectorScenes[MainMenu] = mainS; 

	mainS->init();
	
	actScene = MainMenu;

}

void SceneDirector::changeScene(scene nextScene, bool reinit)
{
	mVectorScenes[nextScene]->setReInit(reinit);
	actScene = nextScene;
}

BaseScene* SceneDirector::getCurrentScene()
{
	std::cout << mVectorScenes[actScene];
	return mVectorScenes[actScene];
}
