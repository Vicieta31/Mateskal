#include "CambioNivel.h"

#include <iostream>

#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

CambioNivel::CambioNivel()
{
	_cambioNivel = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/gato.png", 1);

	_posX = 500;
	_posY = 500;
}

CambioNivel::~CambioNivel()
{
}

void CambioNivel::Init()
{
}

void CambioNivel::Update(float characterPosX, float characterPosY)
{
}

void CambioNivel::Render()
{
	// Render CambioNivel
	VideoManager::getInstance()->renderGraphic(_cambioNivel, _posX, _posY, 80, 80);
}

bool CambioNivel::CheckCharacterCollisionL(Character& character)
{
	float distance = CalculateDistance(_posX, _posY, character.GetPosX(), character.GetPosY());
	if (distance < 40) { // Radio de colisión del personaje
		return true; // Si se tocan
	}
	return false; // Si no se tocan
}

float CambioNivel::CalculateDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
