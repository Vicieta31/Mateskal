#pragma once
#include <cmath>

class Enemy
{
private:
    int _enemy;

    float _posX;
    float _posY;

    float vEnemy;

public:
    Enemy();
    ~Enemy();

    void Init();
    void Update(float characterPosX, float characterPosY); // Se pasan las posiciones del personaje

    void Render();

    float CalculateDistance(float x1, float y1, float x2, float y2); // Calcular la distancia entre dos puntos
    void MoveTowards(float targetX, float targetY); // Mover al enemigo hacia un punto
};

