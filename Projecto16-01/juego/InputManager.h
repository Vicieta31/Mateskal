#pragma once
#include <SDL.h>

class InputManager
{

private:

	int pDirection;

	bool pPause;

	int pShot;

	InputManager();

	static InputManager* pInstance;

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

