#pragma once
class Character
{
private:
	int _dir;
	int _disp;

	int _character;

	float _posX;
	float _posY;

	void Move(); //Calcula posicion personaje
	void Shot();

public:

	Character();
	~Character();

	void Init();
	void Update(int dir, int shot); //Actualiza la direccion del personaje y la bala
	void Render();


};

