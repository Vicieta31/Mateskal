#pragma once
#include "SDL.h"

class VideoManager
{
public:
	~VideoManager();

	/*!
		Draws the graphic img at the specified position and scale.
		\param img Code of the graphic
		\param posX X Destination for the graphic
		\param posY Y Destination for the graphic
		\param width Destination width for the graphic
		\param width Destination height for the graphic
	*/
	void renderGraphic(int img, int posX, int posY, int width, int height);

	/*!
		Clears the screen and paints it over with the color.
		\param colorKey Color to use when clearing
	*/
	void clearScreen(unsigned int colorKey);

	/*!
		Updates the screen one frame.
	*/
	void updateScreen();

	/*!
		Pauses the screen for the specified time.
		\param ms Time to stay paused in ms.
	*/
	void waitTime(int ms);

	/*!
		Closes the screen, and the game.
	*/
	void close();

	SDL_Window* gWindow;
	SDL_Renderer* gRenderer;

	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	/*
		\return Instance of VideoManager (Singleton).
	*/
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

