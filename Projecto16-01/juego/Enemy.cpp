#include "Enemy.h"
#include "Character.h"

#include <iostream>

#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

Enemy::Enemy()
{
	_enemy = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.png", 1);

	_health = 5;

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
	float chaseDistance = 400.0f;

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

void Enemy::CheckCharacterCollisionE(Character& character)
{
	float distance = CalculateDistance(_posX, _posY, character.GetPosX(), character.GetPosY());
	if (distance < 40) { // Radio de colisión del personaje
		character.ReduceHealth();
	}
}

void Enemy::ReduceHealth()
{
	_health -= 1; // Reducir la salud del enemigo en 1
	if (_health <= 0) {
		// El enemigo ha perdido todas sus vidas
		_posX = rand() % 999;
		_posY = rand() % 639;
		_health = 5;
	}
}

float Enemy::CalculateDistance(float x1, float y1, float x2, float y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void Enemy::MoveTowards(float targetX, float targetY)
{
	// Calcula la dirección hacia la que debe moverse
	float deltaX = targetX - _posX;
	float deltaY = targetY - _posY;
	float distance = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

	// Normaliza el vector de dirección
	float dirX = deltaX / distance;
	float dirY = deltaY / distance;

	// Mueve al enemigo hacia el personaje
	_posX += dirX * vEnemy;
	_posY += dirY * vEnemy;
}

Enemy* Enemy::CreateEnemy()
{
	// Crear nuevo enemigo dinámicamente
	Enemy* newEnemy = new Enemy();

	// Definir posiciones
	static const Position enemyPositions[] = {
		{800, 500},   // Pos 1
		{600, 200},   // Pos 2
		{500, 400},   // Pos 3
		{700, 300},   // Pos 4
		{900, 100}    // Pos 5
	};

	// Vector para mantener las posiciones disponibles
	static std::vector<Position> availablePositions(enemyPositions, enemyPositions + sizeof(enemyPositions) / sizeof(enemyPositions[0]));

	// Seleccionar una posición aleatoria para el nuevo enemigo
	int randomIndex = rand() % availablePositions.size();
	newEnemy->_posX = availablePositions[randomIndex].x;
	newEnemy->_posY = availablePositions[randomIndex].y;

	// Eliminar la posición seleccionada de las disponibles
	availablePositions.erase(availablePositions.begin() + randomIndex);

	newEnemy->_health = 5;
	return newEnemy;
}