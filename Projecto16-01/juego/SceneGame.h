#pragma once
#include <iostream>
#include <vector>

#include "VideoManager.h"
#include "InputManager.h"
#include "ResourceManager.h"

#include "BaseScene.h"
#include "SceneDirector.h"
#include "CargarMapas.h"

#include "CambioNivel.h"
#include "Character.h"
#include "Enemy.h"

#include "Glboals.h"
class SceneGame : public BaseScene
{
private:
	CargarMapas MyMap;

	Sint32 backgroundImage;

	int direccion = 0;
	int dispDireccion = 0;

	CambioNivel cambioNivel;
	Character character;

	std::vector<Enemy*> enemies;

public:
	SceneGame();
	~SceneGame();

	void init();
	void update();
	void render();
};
