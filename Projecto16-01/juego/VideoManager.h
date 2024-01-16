#pragma once
#include "SDL.h"

class VideoManager
{
public:
	~VideoManager();
	void renderGraphic(int img, int posX, int posY, int width, int height);
	void clearScreen(unsigned int colorKey);
	void updateScreen();
	void waitTime(int ms);
	void close();

	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	static VideoManager* getInstance() {

		if (pInstance == NULL) {
			pInstance = new VideoManager(1080, 720);
		}

		return pInstance;

	};

protected:
	VideoManager(int w, int h);

private:
	static VideoManager* pInstance;
};

