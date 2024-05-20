#pragma once
#ifndef TILESET_H
#define TILESET_H

#include <string>
#include <SDL.h>
#include "ResourceManager.h" // Incluye tu archivo de encabezado de ResourceManager


class Tileset
{
	int _firstID;
	int _tileWidth;
	int _tileHeight;
	Sint32 _gfxID; // Cambiado a Sint32 para almacenar el ID de la textura en ResourceManager

	std::string _filename;

public:
	Tileset();
	~Tileset();
	int loadTileset(const char* filename);
	void setFirstID(int value) { _firstID = value; };
	void setTileWidth(int value) { _tileWidth = value; };
	void setTileHeight(int value) { _tileHeight = value; };

	int getTileWidth() { return _tileWidth; };
	int getTileHeight() { return _tileHeight; };

	SDL_Texture* getIMG() {
		return ResourceManager::getInstance()->getGraphicByID(_gfxID);
	};

};

#endif TILESET_H