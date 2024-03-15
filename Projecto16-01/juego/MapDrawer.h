#pragma once
#include <SDL.h>
#include <string>
#include "XMLDefs.h"

class MapDrawer
{
private:

public:

	MapDrawer();
	~MapDrawer();

	/*!
		Draws one tile. To be used in a loop.
		\param Tiles Pointer to the whole Tileset.
		\param Details Tileset struct with details. Get from XMLReader.
		\param Renderer Rederer for the project.
		\param dX X coordinate of where the tile should be drawn.
		\param dY Y coordinate of where the tile should be drawn.
		\param tID ID of the tile that sould be drawn.
	*/
	void DrawTile(SDL_Texture* Tiles, Tileset Details, SDL_Renderer* Renderer, int dX, int dY, int tID);

};

