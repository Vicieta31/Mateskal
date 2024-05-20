#include "Tileset.h"

Tileset::Tileset() {
    _firstID = 0;
    _tileWidth = 0;
    _tileHeight = 0;
    _gfxID = -1;
}

Tileset::~Tileset() {}

int Tileset::loadTileset(const char* filename) {
    _filename = filename;

    _gfxID = ResourceManager::getInstance()->loadAndGetGraphicID(filename);

    if (_gfxID == -1) {
        // Maneja el error de carga de textura
        return -1;
    }

    // Realiza cualquier otra inicialización necesaria, por ejemplo, obtener el ancho y alto del tileset

    return 0;
}