#include "resourceManager.h"
#include "VideoManager.h"
#include <iostream>

ResourceManager::~ResourceManager(void)
{
}

void ResourceManager::removeGraphic(const char* file)
{
	std::map<std::string, Sint32>::iterator ite = mIDMap.find(file);

	Sint32 returnValue = -1;
	if (ite == mIDMap.end())
	{
		std::cout << "Intentando borrar el grafico " << file << " Error " << std::endl;
		return;
	}
	Uint32 ID = ite->second;

	std::cout << "Intentando borrar el grafico " << file << " Encontrado " << std::endl;
	SDL_DestroyTexture(getGraphicByID(ID));
	mGraphicsVector[ID] = NULL;
	mIDMap.erase(file);

	mFirstFreeSlot = updateFirstFreeSlotGraphic();
}

Sint32 ResourceManager::loadAndGetGraphicID(const char* file)
{
	std::map<std::string, Sint32>::iterator it;
	it = mIDMap.find(file);

	Sint32  returnValue = -1;
	if (it == mIDMap.end())
	{
		std::cout << "Intenta a�adir el grafico " << file << " (first Request) " << std::endl;
		Sint32 index = addGraphic(file);
		if (index == -1)
		{
			std::cout << "No se ha encontrado " << file << " en el disco" << std::endl;
		}
		returnValue = index;
	}
	else
	{
		std::cout << "Imagen " << file << " ya cargada previamente, obteniendo ID existente" << std::endl;
		returnValue = it->second;
	}
	return returnValue;
}


void ResourceManager::getGraphicSize(Sint32 img, int& width, int& height)
{
	SDL_Texture* imgSurface = getGraphicByID(img);
	if (imgSurface != NULL)
	{
		SDL_QueryTexture(imgSurface, NULL, NULL, &width, &height);
	}
	else
	{
		width = 0;
		height = 0;
	}
}

Uint16 ResourceManager::getGraphicWidth(Sint32 img)
{
	SDL_Texture* imgSurface = getGraphicByID(img);
	if (imgSurface != NULL)
	{
		int width;
		SDL_QueryTexture(imgSurface, NULL, NULL, &width, NULL);

		return width;
	}
	else
	{
		return 0;
	}
}

Uint16 ResourceManager::getGraphicHeight(Sint32 img)
{
	SDL_Texture* imgSurface = getGraphicByID(img);
	if (imgSurface != NULL)
	{
		int height;
		SDL_QueryTexture(imgSurface, NULL, NULL, NULL, &height);

		return height;
	}
	else
	{
		return 0;
	}
}

SDL_Texture* ResourceManager::getGraphicByID(Sint32 ID)
{
	if (ID < 0)
	{
		return NULL;
	}
	if (ID < static_cast<Sint32>(mGraphicsVector.size()))
	{
		return mGraphicsVector[ID];
	}
	else
	{
		return NULL;
	}
}

std::string ResourceManager::getGraphicPathByID(Sint32 ID)
{

	return std::string();
}

void ResourceManager::setAlphaGraphic(Sint32 ID, Uint8 alpha_value)
{
	SDL_SetTextureAlphaMod(getGraphicByID(ID), alpha_value);
}

void ResourceManager::printLoadedGraphics()
{

}

Sint32 ResourceManager::createGraphic(const char* name, Uint16 width, Uint16 height)
{
	return 0;
}

ResourceManager* ResourceManager::pInstance = NULL;

ResourceManager::ResourceManager(void)
{
	mFirstFreeSlot = 0;
}

Sint32 ResourceManager::addGraphic(const char* file)
{
	SDL_Texture* graph = NULL;
	graph = IMG_LoadTexture(VideoManager::getInstance()->gRenderer, file);

	if (graph == NULL)
	{
		std::cout << "Error al cargar la imagen: " << file << ": " << SDL_GetError() << std::endl;
		return -1;
	}
	else
	{
		Sint32 returnValue = 0;
		if (mFirstFreeSlot == mGraphicsVector.size())
		{
			mGraphicsVector.push_back(graph);
			mFirstFreeSlot++;
			returnValue = mGraphicsVector.size() - 1;
		}
		else
		{
			mGraphicsVector[mFirstFreeSlot] = graph;
			Uint32 temporal = mFirstFreeSlot;
			mFirstFreeSlot = updateFirstFreeSlotGraphic();
			returnValue = temporal;
		}
		if (returnValue != -1)
		{
			mIDMap.insert(std::pair<std::string, Sint32>(file, returnValue));
		}
		return returnValue;
	}
}

Uint32 ResourceManager::updateFirstFreeSlotGraphic()
{
	for (Uint32 i = 0; i < mGraphicsVector.size(); i++)
	{
		if (mGraphicsVector[i] == NULL)
		{
			return i;
		}
	}
	return mGraphicsVector.size();
}