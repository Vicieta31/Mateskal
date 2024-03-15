#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <string>
#include "XMLReader.h"
#include "MapDrawer.h"
#include "XMLDefs.h"

class MapReadWriter
{

private:

	MapReadWriter();

	static MapReadWriter* pInstance;

	Tileset LevelTiles;

	XMLReader Reader;

	MapDrawer Writer;

	std::string Level;

	SDL_Texture* gTileset;

public:

	~MapReadWriter();

	/*!
		Changes level to be drawn.
		\param Level Path to the level xml.
	*/
	void ChangeLevel(std::string Level);

	/*!
		Initializes the map loading & drawing.
		\param Level Path to the first level xml.
	*/
	void Init(std::string Level);

	/*!
		Updates the params for the current drawing of the level.
	*/
	void Update();

	/*!
		Renders the current level, tile by tile.
	*/
	void Render();

	static MapReadWriter* getInstance() {

		if (pInstance == NULL) {
			pInstance = new MapReadWriter;
		}

		return pInstance;

	};

};

