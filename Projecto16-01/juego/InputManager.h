#pragma once
#include <SDL.h>
#include "Glboals.h"

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

	bool kEnter;

public:

	~InputManager();

	/*
		Reads inputs, meant to be used in the Game Loop.
	*/
	void Update();

	/*
		Returns the Direction the player is currently moving as an Int.
	*/
	int GetDirection() { return pDirection; };

	/*
		Returns if the game is paused in a bool.
	*/
	bool GetPause() { return pPause; };
	void SetPause() { pPause = true; };

	/*
		Returns the Direction the player is currently shooting as an Int.
	*/
	int GetShot() { return pShot; };

	bool GetEnter() { return kEnter; };

	/*
		\return Instance of InputManager (Singleton).
	*/
	static InputManager* getInstance() {

		if (pInstance == NULL) {
			pInstance = new InputManager;
		}

		return pInstance;
	};
};

