#pragma once
#include <SDL2/SDL.h>
#include <string>

#include "GameLoop.h"
#include "AssetsManager.h"

using namespace LegendsCore::Assets;

class Sprite
{
public:	
	Sprite();
	void loadTexture(std::string path, std::string file);
	~Sprite();
	SDL_Texture* texture;
	int width = 64;
	int height = 64;
private:
	SDL_Surface* surface;
	AssetsManager assetsManager;
};