#include <iostream>
#include "Character.h"

#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

Character::Character()
{
	_dir = 0;
	_disp = 0;

	_character = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg");

	_posX = 0;
	_posY = 0;
}

void Character::Init()
{
}

void Character::Update(int dir, int shot)
{
	_dir = dir;
	_disp = shot;

	Move();
	Shot();
}

void Character::Render()
{
	VideoManager::getInstance()->renderGraphic(_character, _posX, _posY, 80, 80);
}

Character::~Character()
{
}

void Character::Move()
{
	switch (_dir)
	{
	//ARRIBA
	case 1:
		if (_posY > 0)
		{
			_posY--;
		}
		break;
	//ARRIBA + DERECHA
	case 2:
		if ((_posY > 0) && (_posX < 1000))
		{
			_posX += 0.4f;
			_posY -= 0.4f;
		}
		break;
	//DERECHA
	case 3:
		if (_posX < 1000)
		{
			_posX++;
		}
		break;
	//DERECHA + ABAJO
	case 4:
		if ((_posX < 1000) && (_posY < 640))
		{
			_posX += 0.4f;
			_posY += 0.4f;
		}
		break;
	//ABAJO
	case 5:
		if (_posY < 640)
		{
			_posY++;
		}
		break;
	//ABAJO + IZQUIERDA
	case 6:
		if ((_posY < 640) && (_posX > 0))
		{
			_posX -= 0.4f;
			_posY += 0.4f;
		}
		break;
	//IZQUIERDA
	case 7:
		if (_posX > 0)
		{
			_posX--;
		}
		break;
	//IZQUIERDA + ARRIBA
	case 8:
		if ((_posX > 0) && (_posY > 0))
		{
			_posX -= 0.4f;
			_posY -= 0.4f;
		}
		break;
	}
}

//FALTA POR HACER
void Character::Shot()
{
}