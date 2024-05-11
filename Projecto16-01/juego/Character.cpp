#include "Character.h"
#include "Enemy.h"

#include <iostream>

#include "VideoManager.h"
#include "ResourceManager.h"
#include "InputManager.h"

Character::Character()
{
	_dir = 0;
	_disp = 0;

	_character = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg", 1);
	_bullet = ResourceManager::getInstance()->loadAndGetGraphicID("TestResources/puke.jpeg", 1);

	_health = 10;

	_posX = 10;
	_posY = 10;

	vNormal = 0.3f; // velocidad direccion normal
	vDiagonal = 0.1f; // velocidad direccion diagonal
	vBullet = 0.5f; // Velocidad bala

	_shotTimer = 0;
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

	// Actualizar el temporizador de disparo
	if (_shotTimer > 0) {
		_shotTimer--;
	}
}

void Character::Render()
{
	// Render Character
	VideoManager::getInstance()->renderGraphic(_character, _posX, _posY, 80, 80);

	// Render bullets
	for (int i = 0; i < _bullets.size(); ++i) {
		const Bullet& bullet = _bullets[i];
		VideoManager::getInstance()->renderGraphic(_bullet, bullet.posbX, bullet.posbY, 10, 10);
	}
}

void Character::ReduceHealth()
{
	_health -= 1; // Reducir la salud del personaje en 1
	if (_health <= 0) {
		// El personaje ha perdido todas sus vidas
	}
}

void Character::CheckBulletCollision(Enemy& enemy)
{
	for (int i = 0; i < _bullets.size(); ++i) {
		const Bullet& bullet = _bullets[i];
		float distance = enemy.CalculateDistance(bullet.posbX, bullet.posbY, enemy.GetPosX() + 25, enemy.GetPosY() + 25);
		if (distance < 40) { // radio de colisión del enemigo
			enemy.ReduceHealth();
			_bullets.erase(_bullets.begin() + i);
			i--;
		}
	}
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
			_posY-= vNormal;
		}
		break;
	//ARRIBA + DERECHA
	case 2:
		if ((_posY > 0) && (_posX < 1000))
		{
			_posX += vDiagonal;
			_posY -= vDiagonal;
		}
		break;
	//DERECHA
	case 3:
		if (_posX < 1000)
		{
			_posX+= vNormal;
		}
		break;
	//DERECHA + ABAJO
	case 4:
		if ((_posX < 1000) && (_posY < 640))
		{
			_posX += vDiagonal;
			_posY += vDiagonal;
		}
		break;
	//ABAJO
	case 5:
		if (_posY < 640)
		{
			_posY+= vNormal;
		}
		break;
	//ABAJO + IZQUIERDA
	case 6:
		if ((_posY < 640) && (_posX > 0))
		{
			_posX -= vDiagonal;
			_posY += vDiagonal;
		}
		break;
	//IZQUIERDA
	case 7:
		if (_posX > 0)
		{
			_posX-= vNormal;
		}
		break;
	//IZQUIERDA + ARRIBA
	case 8:
		if ((_posX > 0) && (_posY > 0))
		{
			_posX -= vDiagonal;
			_posY -= vDiagonal;
		}
		break;
	}
}

void Character::Shot() {
	// Crear nueva bala al disparar
	if (_disp != 0 && _shotTimer == 0) {
		Bullet newBullet;
		newBullet.posbX = _posX + 35;
		newBullet.posbY = _posY + 35;
		newBullet.dirb = _disp;
		newBullet.timer = 800;  // Temporizador de vida de la bala
		_bullets.push_back(newBullet);

		_shotTimer = _CooldownBullet; // Reiniciar el temporizador de disparo
	}

	// Actualizar la posición de cada bala
	for (int i = 0; i < _bullets.size(); ++i) {
		Bullet& bullet = _bullets[i];
		switch (bullet.dirb) {
		case 1: // ARRIBA
			bullet.posbY -= vBullet; 
			break;
		case 2: // ARRIBA + DERECHA
			bullet.posbX += vBullet;
			bullet.posbY -= vBullet;
			break;
		case 3: // DERECHA
			bullet.posbX += vBullet;
			break;
		case 4: // DERECHA + ABAJO
			bullet.posbX += vBullet;
			bullet.posbY += vBullet;
			break;
		case 5: // ABAJO
			bullet.posbY += vBullet;
			break;
		case 6: // ABAJO + IZQUIERDA
			bullet.posbX -= vBullet;
			bullet.posbY += vBullet;
			break;
		case 7: // IZQUIERDA
			bullet.posbX -= vBullet;
			break;
		case 8: // IZQUIERDA + ARRIBA
			bullet.posbX -= vBullet;
			bullet.posbY -= vBullet;
			break;
		}

		bullet.timer--;

		// Eliminar la bala si el temporizador llega a 0
		if (bullet.timer <= 0) {
			_bullets.erase(_bullets.begin() + i);
			i--; // Ajustar el índice después de borrar un elemento
		}
	}
}