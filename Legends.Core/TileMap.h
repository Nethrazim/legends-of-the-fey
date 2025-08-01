#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "Sprite.h"

class TileMap
{	
public:
	TileMap();
	TileMap(Uint32 widthTiles, Uint32 hTiles);
	~TileMap();

	Sprite sprite;
	Uint32 wTiles = 256;
	Uint32 hTiles = 256;
	std::string** tileMap;
	void allocate();
	void deallocate();
	
};

