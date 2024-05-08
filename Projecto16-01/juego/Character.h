#pragma once
#include <vector>

struct Bullet {
    float posbX;
    float posbY;
    int dirb;
    int timer;
};

class Character {
private:
    int _dir;
    int _disp;

    int _character;
    int _bullet;

    float _posX;
    float _posY;

    float vNormal; // velocidad direccion normal
    float vDiagonal; // velocidad direccion diagonal
    float vBullet; // Velocidad bala

    std::vector<Bullet> _bullets;

    int _shotTimer;
    const int _CooldownBullet = 600;

    void Move();
    void Shot();

public:
    Character();
    ~Character();

    void Init();
    void Update(int dir, int disp);
    void Render();

    float GetPosX() const { return _posX; } // Obtener la posición X del personaje
    float GetPosY() const { return _posY; } // Obtener la posición Y del personaje

};