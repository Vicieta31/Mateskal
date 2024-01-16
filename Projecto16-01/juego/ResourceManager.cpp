#include "ResourceManager.h"
#include "SDL_image.h"
#include "VideoManager.h"
#include <iostream>

ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager::ResourceManager()
{
	mFirstFreeSlot = 0;
}

ResourceManager::~ResourceManager()
{
}

Sint32 ResourceManager::addGraphic(const char* file, int AlphMod)
{
	Sint32 Return = -1;

	SDL_Texture* Graph1 = NULL;

	Graph1 = IMG_LoadTexture(VideoManager::getInstance()->gRenderer, file);

	if (Graph1 != NULL) {

		switch (AlphMod) {
		case 1:
			SDL_SetTextureBlendMode(Graph1, SDL_BLENDMODE_BLEND);
			break;
		case 2:
			SDL_SetTextureBlendMode(Graph1, SDL_BLENDMODE_ADD);
			break;
		case 3:
			SDL_SetTextureBlendMode(Graph1, SDL_BLENDMODE_MOD);
			break;
		default:
			SDL_SetTextureBlendMode(Graph1, SDL_BLENDMODE_NONE);
			break;
		}

		if (mFirstFreeSlot == mGraphicsVector.size()) {

			mGraphicsVector.push_back(Graph1);

			Return = mGraphicsVector.size() - 1;

			mFirstFreeSlot = mGraphicsVector.size();

			mIDMap.insert(std::pair<std::string, Sint32>(file, Return));

		}
		else {

			mGraphicsVector[mFirstFreeSlot] = Graph1;

			Return = mFirstFreeSlot;

			mIDMap.insert(std::pair<std::string, Sint32>(file, Return));

			ResourceManager::getInstance()->updateFirstFreeSlotGraphic();

		}

	}

	return Return;
}

void ResourceManager::removeGraphic(const char* file)
{
	std::map<std::string, Sint32>::iterator Iterator;

	Iterator = mIDMap.find(file);

	if (Iterator != mIDMap.end()) {

		int id = Iterator->second;

		mIDMap.erase(Iterator);

		SDL_DestroyTexture(mGraphicsVector[id]);

		mGraphicsVector[id] = NULL;

		mFirstFreeSlot = updateFirstFreeSlotGraphic();

	}
}

Uint32 ResourceManager::updateFirstFreeSlotGraphic()
{
	for (int i = 0; i < mGraphicsVector.size(); i++) {

		if (mGraphicsVector[i] == NULL) {

			return i;

		}

	}

	return mGraphicsVector.size();
}

Sint32 ResourceManager::loadAndGetGraphicID(const char* file, int AlphMod)
{
	std::map<std::string, Sint32>::iterator Iterator;

	Iterator = mIDMap.find(file);

	Sint32 Return = -1;

	if (Iterator == mIDMap.end()) {

		Return = addGraphic(file, AlphMod);

	}
	else {

		Return = Iterator->second;

	}
	
	return Return;
}

std::string ResourceManager::getGraphicPathByID(Sint32 ID)
{
	std::map<std::string, Sint32>::iterator Iterator;

	std::string Return = "NULL";

	if ((ID > mGraphicsVector.size()) || (ID < 0)) {

		Return = "NULL";

	}
	else {

		for (Iterator = mIDMap.begin(); Iterator != mIDMap.end(); ++Iterator) {

			if (Iterator->second == ID) {

				Return = Iterator->first;

			}

		}

	}

	return Return;
}

SDL_Texture* ResourceManager::getGraphicByID(Sint32 ID)
{
	SDL_Texture* Return = NULL;

	Return = mGraphicsVector[ID];

	return Return;
}

void ResourceManager::getGraphicSize(Sint32 img, int& width, int& height)
{
	SDL_Texture* Text = getGraphicByID(img);

	SDL_QueryTexture(Text, NULL, NULL, &width, &height);
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
	int Width = 0;

	SDL_Texture* Text = getGraphicByID(img);

	SDL_QueryTexture(Text, NULL, NULL, &Width, NULL);

	return (Uint16)Width;
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
	int Height = 0;

	SDL_Texture* Text = getGraphicByID(img);

	SDL_QueryTexture(Text, NULL, NULL, NULL, &Height);

	return (Uint16)Height;
}

void ResourceManager::setAlphaGraphic(Sint32 ID, Uint8 alpha_value)
{
	SDL_SetTextureAlphaMod(getGraphicByID(ID), alpha_value);
}

void ResourceManager::printLoadedGraphics()
{
	std::map<std::string, Sint32>::iterator Iterator;

	for (Iterator = mIDMap.begin(); Iterator != mIDMap.end(); ++Iterator) {

		std::cout << Iterator->first << std::endl;

	}
}

Sint32 ResourceManager::createGraphic(const char* name, Uint16 width, Uint16 height)
{
	Sint32 Return = -1;

	SDL_Surface* Surf = SDL_CreateRGBSurface(0, width, height, 64, 0xFF, 0xFF00, 0xFF0000, 0xFF000000);

	SDL_Texture* Text = SDL_CreateTextureFromSurface(VideoManager::getInstance()->gRenderer, Surf);

	if (Text != NULL) {

		if (mFirstFreeSlot == mGraphicsVector.size()) {

			mGraphicsVector.push_back(Text);

			Return = mGraphicsVector.size() - 1;

			mFirstFreeSlot = mGraphicsVector.size();

			mIDMap.insert(std::pair<std::string, Sint32>(name, Return));

		}
		else {

			mGraphicsVector[mFirstFreeSlot] = Text;

			Return = mFirstFreeSlot;

			mIDMap.insert(std::pair<std::string, Sint32>(name, Return));

			ResourceManager::getInstance()->updateFirstFreeSlotGraphic();

		}

	}

	return Return;
}


