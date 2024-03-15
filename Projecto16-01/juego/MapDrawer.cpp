#include "MapDrawer.h"

MapDrawer::MapDrawer()
{
}

MapDrawer::~MapDrawer()
{
}

void MapDrawer::DrawTile(SDL_Texture* Tiles, Tileset Details, SDL_Renderer* Renderer, int dX, int dY, int tID)
{

	SDL_Rect TileSource;

	TileSource.w = Details.tWidth;
	TileSource.h = Details.tHeight;

	int Row = tID / Details.Columns;
	int Column = tID % Details.Columns;

	TileSource.x = (Details.Spacing * Column) + (Details.tWidth * Column);
	TileSource.y = (Details.Spacing * Row) + (Details.tHeight * Row);

	SDL_Rect Dest;

	Dest.w = Details.tWidth;
	Dest.h = Details.tHeight;
	Dest.x = dX;
	Dest.y = dY;

	SDL_RenderCopy(Renderer, Tiles, &TileSource, &Dest);

}
