#pragma once
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include "Character.h"

class Enemy
{
private:
    int _enemy;

    int _health;

    float _posX;
    float _posY;

    float vEnemy;

public:
    Enemy();
    ~Enemy();

    void Init();
    void Update(float characterPosX, float characterPosY); // Se pasan las posiciones del personaje
    void Render();

    void CheckCharacterCollision(Character& character);

    void ReduceHealth(); // Cuando recibe daño

    float CalculateDistance(float x1, float y1, float x2, float y2); // Calcular la distancia entre dos puntos
    void MoveTowards(float targetX, float targetY); // Mover al enemigo hacia un punto

    float GetPosX() const { return _posX; } // Obtener la posición X del enemigo
    float GetPosY() const { return _posY; } // Obtener la posición Y del enemigo

    int GetHealth() const { return _health; } // Obtener la vida del enemigo
};

