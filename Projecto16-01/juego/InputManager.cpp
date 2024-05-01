#include "InputManager.h"
#include <iostream>

InputManager* InputManager::pInstance = NULL;

InputManager::InputManager() 
{

	pDirection = 0;

	pPause = false;

	pShot = 0;

	kUp = false;
	kRight = false;
	kDown = false;
	kLeft = false;

	sUp = false;
	sRight = false;
	sDown = false;
	sLeft = false;

}

InputManager::~InputManager() 
{
}

void InputManager::Update()
{
	SDL_Event cEvent;
	while (SDL_PollEvent(&cEvent)) 
	{
		switch (cEvent.type) 
		{
			case SDL_KEYDOWN:
				switch (cEvent.key.keysym.scancode) 
				{
					case SDL_SCANCODE_UP:
						kUp = true;
						break;
					case SDL_SCANCODE_RIGHT:
						kRight = true;
						break;
					case SDL_SCANCODE_DOWN:
						kDown = true;
						break;
					case SDL_SCANCODE_LEFT:
						kLeft = true;
						break;
					case SDL_SCANCODE_W:
						sUp = true;
						break;
					case SDL_SCANCODE_D:
						sRight = true;
						break;
					case SDL_SCANCODE_S:
						sDown = true;
						break;
					case SDL_SCANCODE_A:
						sLeft = true;
						break;
					case SDL_SCANCODE_ESCAPE:
						pPause = true;
						break;
				}
				break;

			case SDL_KEYUP:
				switch (cEvent.key.keysym.scancode) 
				{
					case SDL_SCANCODE_UP:
						kUp = false;
						break;
					case SDL_SCANCODE_RIGHT:
						kRight = false;
						break;
					case SDL_SCANCODE_DOWN:
						kDown = false;
						break;
					case SDL_SCANCODE_LEFT:
						kLeft = false;
						break;
					case SDL_SCANCODE_W:
						sUp = false;
						break;
					case SDL_SCANCODE_D:
						sRight = false;
						break;
					case SDL_SCANCODE_S:
						sDown = false;
						break;
					case SDL_SCANCODE_A:
						sLeft = false;
						break;
					case SDL_SCANCODE_ESCAPE:
						pPause = false;
						break;
					}
				break;
		}

	}

	if (kUp == true)
	{
		//std::cout << "Up\n";
	}
	if (kDown == true)
	{
		//std::cout << "Down\n";
	}
	if (kLeft == true)
	{
		//std::cout << "Left\n";
	}
	if (kRight == true)
	{
	//	std::cout << "Right\n";
	}

	if (pPause != true) {

		bool kVertCancel = false;
		bool kHorCancel = false;
		bool sVertCancel = false;
		bool sHorCancel = false;

		//Move Direction

		//Determines if opposing directions are simultaneously pressed or unpressed

		if (((kUp == true) && (kDown == true))||
			((kUp == false) && (kDown == false))
			) 
		{
			kVertCancel = true;
		}

		if (((kRight == true) && (kLeft == true))||
			((kRight == false) && (kLeft == false))
			) 
		{
			kHorCancel = true;
		}

		//Determines what direction to move the player with the enum.
		//If two opposing keys are pressed or unpressed at the same time, the direction is ignored.
		//If they aren't, then the game assigns a direction, checking verticals before horizontals.

		if (kVertCancel != true) 
		{
			if (kUp == true) 
			{
				if (kHorCancel != true)
				{
					if (kLeft == true) 
					{
						pDirection = dUPLEFT;
					}
					if (kRight == true) 
					{
						pDirection = dUPRIGHT;
					}
				}
				else 
				{
					pDirection = dUP;
				}
			}
			else 
			{
				if (kHorCancel != true) 
				{
					if (kLeft == true) 
					{
						pDirection = dDOWNLEFT;
					}
					if (kRight == true) 
					{
						pDirection = dDOWNRIGHT;
					}
				}
				else 
				{
					pDirection = dDOWN;
				}
			}
		}
		else 
		{
			if (kHorCancel != true) 
			{
				if (kRight == true)
				{
					pDirection = dRIGHT;
				}
				else 
				{
					pDirection = dLEFT;
				}
			}
			else 
			{ 
				pDirection = dNEUTRAL; 
			}
		}

		//Shot Direction

		//Determines if opposing directions are simultaneously pressed or unpressed

		if (((sUp == true) && (sDown == true)) ||
			((sUp == false) && (sDown == false))
			) 
		{
			sVertCancel = true;
		}

		if (((sRight == true) && (sLeft == true)) ||
			((sRight == false) && (sLeft == false))
			) 
		{
			sHorCancel = true;
		}

		//Determines what direction to move the projectile with the enum.
		//If two opposing keys are pressed or unpressed at the same time, the direction is ignored.
		//If they aren't, then the game assigns a direction, checking verticals before horizontals.

		if (sVertCancel != true) 
		{
			if (sUp == true) 
			{
				if (sHorCancel != true) 
				{
					if (sLeft == true) 
					{
						pShot = dUPLEFT;
					}
					if (sRight == true) 
					{
						pShot = dUPRIGHT;
					}
				}
				else
				{
					pShot = dUP;
				}
			}
			else 
			{
				if (sHorCancel != true) 
				{
					if (sLeft == true) 
					{
						pShot = dDOWNLEFT;
					}
					if (sRight == true) 
					{
						pShot = dDOWNRIGHT;
					}
				}
				else
				{
					pShot = dDOWN;
				}
			}
		}
		else 
		{
			if (sHorCancel != true) 
			{
				if (sRight == true) 
				{
					pShot = dRIGHT;
				}
				else 
				{
					pShot = dLEFT;
				}
			}
			else 
			{
				pShot = dNEUTRAL;
			}
		}
	}
}
