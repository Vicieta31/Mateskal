#pragma once
#include <iostream>
#include "BaseScene.h"
#include "VideoManager.h"
#include "InputManager.h"
#include "SceneDirector.h"
#include "ResourceManager.h"
#include "CargarMapas.h"

#include "Glboals.h"
class SceneGame : public BaseScene
{
private:
	CargarMapas MyMap;

	Sint32 backgroundImage;
public:
	SceneGame();
	~SceneGame();

	void init();
	void update();
	void render();
};
