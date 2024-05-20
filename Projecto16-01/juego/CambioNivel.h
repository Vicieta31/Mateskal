#pragma once
#include <cmath>

#include "Character.h"

class CambioNivel
{
private:

	int _cambioNivel;

	float _posX;
	float _posY;

public:
	CambioNivel();
	~CambioNivel();

	void Init();
	void Update(float characterPosX, float characterPosY); // Se pasan las posiciones del personaje
	void Render();

	bool CheckCharacterCollisionL(Character& character);

	float CalculateDistance(float x1, float y1, float x2, float y2); // Calcular la distancia entre dos puntos

	float GetPosX() const { return _posX; } // Obtener la posición X del cambio de nivel
	float GetPosY() const { return _posY; } // Obtener la posición Y del cambio de nivel
};

