#pragma once
#include <SDL.h>
#include <string>
#include "AssetsManager.h"

using namespace LegendsCore::Assets;

class Sprite
{
public:	
	Sprite();
	void loadTexture(std::string path, std::string file);
	~Sprite();
	SDL_Texture* texture;

private:
	SDL_Surface* surface;
	AssetsManager assetsManager;
};