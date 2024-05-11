#include <iostream>

#include "Enemy.h"

#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

Enemy::Enemy()
{
	_enemy = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg", 1);

	_posX = 500;
	_posY = 500;

	vEnemy = 0.1f;
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
}

void Enemy::Update(float characterPosX, float characterPosY)
{
	// Calcula la distancia entre el enemigo y el personaje
	float distance = CalculateDistance(_posX, _posY, characterPosX, characterPosY);

	// Define el umbral de distancia para comenzar a perseguir al personaje
	float chaseDistance = 600.0f;

	// Si la distancia es menor que el umbral, mueve al enemigo hacia el personaje
	if (distance < chaseDistance) {
		MoveTowards(characterPosX, characterPosY);
	}
}

void Enemy::Render()
{
	// Render Enemy
	VideoManager::getInstance()->renderGraphic(_enemy, _posX, _posY, 80, 80);
}

float Enemy::CalculateDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void Enemy::MoveTowards(float targetX, float targetY)
{
	// Calcula la direcci�n hacia la que debe moverse
	float deltaX = targetX - _posX;
	float deltaY = targetY - _posY;
	float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	// Normaliza el vector de direcci�n
	float dirX = deltaX / distance;
	float dirY = deltaY / distance;

	// Mueve al enemigo hacia el personaje
	_posX += dirX * vEnemy;
	_posY += dirY * vEnemy;
}