#include "CargarMapas.h"


Character Jugador;
Tileset casilla;
VideoManager* renderer;
CargarMapas::CargarMapas()
{
	_width = 0;
	_height = 0;
	_tileWidth = 32;
	_tileHeight = 32;

	for (size_t i = 0; i < NUM_CAPAS; i++)
	{
		Layers[i].resize(0);
	}

	_CamaraX = 0;
	_CamaraY = 0;
}

CargarMapas::~CargarMapas()
{

}

int CargarMapas::loadMap(const char* filename)
{
	using namespace tinyxml2;

	XMLDocument doc;
	if (doc.LoadFile(filename) != XML_SUCCESS) {
		std::cout << "Error XML: " << doc.ErrorStr();
		return 1;
	}
	XMLElement* map = doc.FirstChildElement(); // <map>
	_width = std::stoi(map->Attribute("width"));
	_height = std::stoi(map->Attribute("height"));
	_tileWidth = std::stoi(map->Attribute("tilewidth"));
	_tileHeight = std::stoi(map->Attribute("tileheight"));

	XMLElement* tileset = map->FirstChildElement("tileset");
	_tiles.loadTileset((tileset->FirstChildElement("image"))->Attribute("source"));
	_tiles.setFirstID(std::stoi(tileset->Attribute("firstgid")));
	_tiles.setTileWidth(std::stoi(tileset->Attribute("tilewidth")));
	_tiles.setTileHeight(std::stoi(tileset->Attribute("tileheight")));

	XMLElement* layer = map->FirstChildElement("layer");
	for (size_t i = 0; i < NUM_CAPAS; i++)
	{
		std::string layerTXT;
		layerTXT = layer->FirstChildElement("data")->GetText();

		//Neteja el String
		size_t pos = 0;
		size_t nextPos = 0;
		while (nextPos != std::string::npos)
		{
			nextPos = layerTXT.find(',', pos);
			if (nextPos != std::string::npos)
			{
				int value = std::stoi(layerTXT.substr(pos, nextPos - pos));
				Layers[i].push_back(value);
				//std::cout << value << "\n";
				pos = nextPos + 1;
			}
			else {
				// Ultim valor
				int value = std::stoi(layerTXT.substr(pos, layerTXT.size() - pos));
				Layers[i].push_back(value);
				//std::cout << value << "\n";
			}
		}
		layer = layer->NextSiblingElement("layer");
	}
	return 0;
}
void CargarMapas::setCameraPosition(int x, int y) {
	// Mover la cámara a la misma posición que el jugador
	_CamaraX = x - (SCREEN_WIDTH / 2);
	_CamaraY = y - (SCREEN_HEIGHT / 2);

	// Asegurarnos de que la cámara no salga del mapa
	_CamaraX = std::max(0, std::min(_CamaraX, _width * _tileWidth - SCREEN_WIDTH));
	_CamaraY = std::max(0, std::min(_CamaraY, _height * _tileHeight - SCREEN_HEIGHT));
}


// Les definicions de SDL no haurien de ser-hi
void CargarMapas::render()
{
	SDL_Rect rectS, rectT;
	int ID;
	int CellX, CellY;
	int tileW = _tiles.getTileWidth();
	int tileH = _tiles.getTileHeight();
	int tileSP = 1;

	int init_X_Tile = _CamaraX / _tileWidth;
	int last_X_Tile = (2 + SCREEN_WIDTH / _tileWidth) + init_X_Tile;
	if (last_X_Tile > _width)
	{
		last_X_Tile = _width;
	}

	int init_Y_Tile = _CamaraY / _tileHeight;
	int last_Y_Tile = (2 + SCREEN_WIDTH / _tileHeight) + init_Y_Tile;
	if (last_Y_Tile > _height)
	{
		last_X_Tile = _width;
	}

	for (size_t i = 0; i < 1; i++)
	{
		for (size_t tmY = 0; tmY < _height; tmY++)
		{
			for (size_t tmX = init_X_Tile; tmX < last_X_Tile; tmX++)
			{
				rectT.x = tmX * tileW;
				rectT.y = tmY * tileH;
				rectT.w = tileW;
				rectT.h = tileH;
				ID = Layers[i][tmY * _width + tmX] - 1;  // Important el -1!!
				if (ID >= 0) {
					CellX = ID % 16;
					CellY = ID / 16;
					rectS.x = CellX * tileW;
					rectS.y = CellY * tileH;
					rectS.w = tileW;
					rectS.h = tileH;
					rectT.x = rectT.x - _CamaraX;
					rectT.y = rectT.y - _CamaraY;
					SDL_RenderCopy(VideoManager::getInstance()->gRenderer, _tiles.getIMG(), &rectS, &rectT);
				}
			}
		}
	}
}
