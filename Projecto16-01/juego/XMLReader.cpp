#include "XMLReader.h"
#include <iostream>

XMLReader::XMLReader()
{

	lTiles.tCount = -1;
	lTiles.tWidth = -1;
	lTiles.tHeight = -1;
	lTiles.Spacing = -1;
	lTiles.Columns = -1;

	lWidth = 0;
	lHeight = 0;

}

XMLReader::~XMLReader()
{

}

bool XMLReader::CheckLoad(std::string FilePath)
{

	bool Return = true;
	if (Level.LoadFile(FilePath.c_str()) != tinyxml2::XML_SUCCESS) {
		std::cout << "Error XML: " << Level.ErrorStr();
		Return = false;
	}
	return Return;

}

void XMLReader::BasicTileData()
{

	tinyxml2::XMLElement* root = Level.FirstChildElement();
	tinyxml2::XMLElement* element = root->FirstChildElement();
	lTiles.tCount = std::stoi(element->Attribute("tilecount"));
	lTiles.tWidth = std::stoi(element->Attribute("tilewidth"));
	lTiles.tHeight = std::stoi(element->Attribute("tileheight"));
	lTiles.Spacing = std::stoi(element->Attribute("spacing"));
	lTiles.Columns = std::stoi(element->Attribute("columns"));

	tinyxml2::XMLElement* image = element->FirstChildElement();
	lTiles.SourceImage = image->Attribute("source");

}

void XMLReader::LevelWidthHeight() 
{

	tinyxml2::XMLElement* root = Level.FirstChildElement();
	tinyxml2::XMLElement* element = root->FirstChildElement();
	element = element->NextSiblingElement();
	element = element->NextSiblingElement();
	int lWidth = std::stoi(element->Attribute("width"));
	int lHeight = std::stoi(element->Attribute("height"));

}

void XMLReader::LevelTilesStorer()
{

	tinyxml2::XMLElement* root = Level.FirstChildElement();
	tinyxml2::XMLElement* element = root->FirstChildElement();
	element = element->NextSiblingElement();
	element = element->NextSiblingElement();
	tinyxml2::XMLElement* data = element->FirstChildElement();
	std::string Raw = data->GetText();
	std::string LevelText;

	for (int i = 0; i < (int)Raw.size(); i++) {

		if (Raw[i] != '\n') {

			LevelText += Raw[i];

		}

	}

	std::string Chunk;

	for (int i = 0; i < LevelText.size(); i++) {

		if (LevelText[i] != ',') {

			Chunk += LevelText[i];

		}
		else {

			LevelTiles.push_back(stoi(Chunk));

			Chunk.clear();

		}

	}

	LevelTiles.push_back(stoi(Chunk));

	Chunk.clear();

}

int XMLReader::FileLoad(std::string FilePath)
{

	int Return = 0;
	if (CheckLoad(FilePath)) {

		BasicTileData();

		LevelWidthHeight();

		LevelTilesStorer();

	}
	else {

		Return = 1;

	}

	return Return;

}

void XMLReader::ClearLevelTileData() {

	lTiles.tCount = -1;
	lTiles.tWidth = -1;
	lTiles.tHeight = -1;
	lTiles.Spacing = -1;
	lTiles.Columns = -1;

	lWidth = 0;
	lHeight = 0;

	LevelTiles.clear();

}
