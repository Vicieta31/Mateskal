#pragma once
#include <iostream>
#include "BaseScene.h"
#include "VideoManager.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "ResourceManager.h"

#include "Glboals.h"

class SceneMainMenu : public BaseScene
{
private:
	Sint32 backgroundImage;
	int option;
public:
	SceneMainMenu();
	~SceneMainMenu();

	void init();
	void update();
	void render();
};

