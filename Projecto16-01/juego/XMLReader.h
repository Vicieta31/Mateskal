#pragma once
#include <string>
#include <vector>
#include "tinyxml2.h"
#include "XMLDefs.h"

class XMLReader
{

private:

	tinyxml2::XMLDocument Level;

	Tileset lTiles;

	int lWidth;

	int lHeight;

	std::vector<int> LevelTiles;

	std::string Folders;

	/*
		To check if Level XML is loaded correctly.
		Recieves File Path in a string.
		Returns True or False.
		\param FilePath Path to the xml containing the level data.
		\return True if all worked well, false if not.
	*/
	bool CheckLoad(std::string FilePath);

	/*
		Fills internal Struct with general data about the tileset.
	*/
	void BasicTileData();

	/*
		Saves the Level's Width and Height.
	*/
	void LevelWidthHeight();

	/*
		Saves the Level's Tiles by number ID into a vector.
	*/
	void LevelTilesStorer();

public:

	XMLReader();
	~XMLReader();

	/*
		Loads the Tileset into an array of ints, and stores relevant tileset data. 
		!MUST SUCCESFULLY EXECUTE FIRST BEFORE ANY OTHER METHOD.
		\param FilePath Path to the xml containing the level data.
		\return 0 upon success, and 1 upon failure.
	*/
	int FileLoad(std::string FilePath);

	/*
		Returns the ID of the tile at the specified position.
		\param Position Position of the tile in the array.
		\return ID of the tile in Int.
	*/
	int GetLevelTileID(int Position) { 
		return LevelTiles[Position]; 
	};

	//Returns how many tiles tall the level is.
	int GetLevelHeight() { return lHeight; };

	//Returns how many tiles wide the level is.
	int GetLevelWidth() { return lWidth; };

	//Returns the amount of tiles present in the original tileset image.
	int GetTilesetTileCount() { return lTiles.tCount; };

	//Returns the height of the tiles in the original tileset image.
	int GetTilesetTileHeight() { return lTiles.tHeight; };

	//Returns the width of the tiles in the original tileset image.
	int GetTilesetTileWidth() { return lTiles.tWidth; };

	//Returns the spacing between tiles in the original tileset image.
	int GetTilesetSpacing() { return lTiles.Spacing; };

	//Returns the amount of columns of tiles in the original tileset image.
	int GetTilesetColumns() { return lTiles.Columns; };

	//Returns the path to the original tileset image.
	std::string GetTilesetFilePath() { return lTiles.SourceImage; };

	//Clears all variables.
	void ClearLevelTileData();


};

