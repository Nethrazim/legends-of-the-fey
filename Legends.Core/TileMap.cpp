#include "TileMap.h"

TileMap::TileMap() : wTiles(256), hTiles(256), tileMap(nullptr) 
{
	allocate();
}

TileMap::TileMap(Uint32 widthTiles, Uint32 heightTiles)
	:wTiles(widthTiles), hTiles(heightTiles), tileMap(nullptr)
{		
	allocate();
}


void TileMap::allocate() {
	
	if (tileMap)
	{
		deallocate();
	}

	tileMap = new std::string*[wTiles];
	for (int i = 0; i < wTiles; ++i)
	{
		tileMap[i] = new std::string[hTiles];
	}


	for (int i = 0; i < wTiles; ++i)
	{
		for (int j = 0; j < tileMap[i]->length(); ++j)
		{
			*(tileMap[i] + j) = "sample";
		}
	}
}

void TileMap::deallocate()
{
	if (tileMap)
	{
		for (int i = 0; i < wTiles; ++i)
		{
			for (int j = 0; j < tileMap[i]->length(); ++j)
			{
				delete (tileMap[i] + j);
			}
		}
	}
}

TileMap::~TileMap() 
{
	deallocate();
}