#pragma once
#include <SDL_stdinc.h>
#include <SDL.h>
#include <string>


class TileMap
{

	
public:
	TileMap();
	TileMap(Uint32 widthTiles, Uint32 hTiles);
	~TileMap();


	Uint32 wTiles = 256;
	Uint32 hTiles = 256;
	std::string** tileMap;
	void allocate();
	void deallocate();
	
};

