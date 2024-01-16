#include "VideoManager.h"
#include "ResourceManager.h"

VideoManager* VideoManager::pInstance = NULL;

VideoManager::VideoManager(int w, int h)
{
	gWindow = NULL;
	gRenderer = NULL;
	
	SDL_Init(SDL_INIT_VIDEO);

	gWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

	gRenderer = SDL_CreateRenderer(gWindow, -1, NULL);

}

VideoManager::~VideoManager()
{
}

void VideoManager::renderGraphic(int img, int posX, int posY, int width, int height)
{
	SDL_Rect * r = new SDL_Rect, * rectAux = new SDL_Rect;

	r->h = height;
	r->w = width;
	r->x = posX;
	r->y = posY;
	rectAux->h = height;
	rectAux->w = width;
	rectAux->x = 0;
	rectAux->y = 0;

	SDL_Texture* origin = ResourceManager::getInstance()->getGraphicByID(img);

	SDL_RenderCopy(gRenderer, origin, rectAux, r);
}

void VideoManager::clearScreen(unsigned int colorKey)
{
	int r = (colorKey & 0xFF000000) >> 24;

	int g = (colorKey & 0x00FF0000) >> 16;

	int b = (colorKey & 0x0000FF00) >> 8;

	int a = (colorKey & 0x000000FF);

	SDL_SetRenderDrawColor(gRenderer, r, g, b, a);

	SDL_RenderClear(gRenderer);
}

void VideoManager::updateScreen()
{
	SDL_RenderPresent(gRenderer);
}

void VideoManager::waitTime(int ms)
{
	SDL_Delay(ms);
}

void VideoManager::close()
{
	SDL_Quit();
}
