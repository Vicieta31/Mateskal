#pragma once
#include <cmath>
#include <vector>

class Enemy;

struct Bullet {
    float posbX;
    float posbY;
    int dirb;
    int timer;

    Bullet() : posbX(0.0f), posbY(0.0f), dirb(0), timer(0) {}
};

class Character {
private:
    int _dir;
    int _disp;

    int _character;
    int _bullet;

    int _health;

    bool _estaVivo;

    float _posX;
    float _posY;

    float vNormal; // velocidad direccion normal
    float vDiagonal; // velocidad direccion diagonal
    float vBullet; // Velocidad bala

    std::vector<Bullet> _bullets;

    int _shotTimer;
    const int _CooldownBullet = 100;

    void Move();
    void Shot();

public:
    Character();
    ~Character();

    void Init();
    void Update(int dir, int disp);
    void Render();

    void CheckBulletCollision(Enemy& enemy);
    void ReduceHealth(); // Cuando recibe daño

    float GetPosX() const { return _posX; } // Obtener la posición X del personaje
    float GetPosY() const { return _posY; } // Obtener la posición Y del personaje
    
    int GetHealth() const { return _health; } // Obtener la vida del personaje
};