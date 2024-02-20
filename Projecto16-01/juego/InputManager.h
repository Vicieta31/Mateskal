#pragma once
#include <SDL.h>

enum Directions { dNEUTRAL, dUP, dUPRIGHT, dRIGHT, dDOWNRIGHT, dDOWN, dDOWNLEFT, dLEFT, dUPLEFT };

class InputManager
{

private:

	int pDirection;

	bool pPause;

	int pShot;

	InputManager();

	static InputManager* pInstance;

	bool kUp;
	bool kRight;
	bool kDown;
	bool kLeft;

	bool sUp;
	bool sRight;
	bool sDown;
	bool sLeft;

public:

	~InputManager();

	void Update();

	int GetDirection() { return pDirection; };

	bool GetPause() { return pPause; };

	int GetShot() { return pShot; };

	static InputManager* getInstance() {

		if (pInstance == NULL) {
			pInstance = new InputManager;
		}

		return pInstance;

	};

};

