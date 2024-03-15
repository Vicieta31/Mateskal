#include "MapReadWriter.h"
#include "VideoManager.h"

MapReadWriter* MapReadWriter::pInstance = NULL;

MapReadWriter::MapReadWriter()
{

	LevelTiles.Columns = -1;
	LevelTiles.SourceImage = " ";
	LevelTiles.Spacing = -1;
	LevelTiles.tCount = -1;
	LevelTiles.tHeight = -1;
	LevelTiles.tWidth = -1;

	gTileset = IMG_LoadTexture(VideoManager::getInstance()->gRenderer, ".\\data\\tileset.png");

}

MapReadWriter::~MapReadWriter()
{
}

void MapReadWriter::ChangeLevel(std::string Level)
{

	Reader.ClearLevelTileData();

	Reader.FileLoad(Level);

	LevelTiles.Columns = Reader.GetTilesetColumns();
	LevelTiles.SourceImage = Reader.GetTilesetFilePath();
	LevelTiles.Spacing = Reader.GetTilesetSpacing();
	LevelTiles.tCount = Reader.GetTilesetTileCount();
	LevelTiles.tHeight = Reader.GetTilesetTileHeight();
	LevelTiles.tWidth = Reader.GetTilesetTileWidth();

}

void MapReadWriter::Init(std::string Level)
{

	ChangeLevel(Level);

}

void MapReadWriter::Update()
{
}

void MapReadWriter::Render()
{

	int H = Reader.GetLevelHeight();
	int W = Reader.GetLevelWidth();

	int destX = 0;
	int destY = 0;

	int Counter = 0;

	int ID = Reader.GetLevelTileID(Counter);

	for (int y = 0; y < H; y++) {

		for (int x = 0; x < W; x++) {

			int ID = (Reader.GetLevelTileID(Counter) - 1);
			if (ID != -1) {

				Writer.DrawTile(gTileset, LevelTiles, VideoManager::getInstance()->gRenderer, destX, destY, ID);

			}

			destX += Reader.GetTilesetTileWidth();

			Counter++;

		}

		destY += Reader.GetTilesetTileHeight();

		destX = 0;

	}

	SDL_RenderPresent(VideoManager::getInstance()->gRenderer);

}
