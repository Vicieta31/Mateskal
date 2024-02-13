#include <SDL.h>
#include <iostream>
#include "InputManager.h"

using namespace std;

int main(int argc, char* args[]) {

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* tWindow = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 69, 69, SDL_WINDOW_SHOWN);

	while (InputManager::getInstance()->GetPause() != true) {

		InputManager::getInstance()->Update();

	}

	return 0;

}