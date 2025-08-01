#include "Sprite.h"
#include "GameLoop.h"

Sprite::Sprite(): assetsManager()
{
	surface = nullptr;
	texture = nullptr;
}

void Sprite::loadTexture(std::string path, std::string file) 
{
	assetsManager.Load(path, file, surface);
	texture = SDL_CreateTextureFromSurface(GameLoop::renderer, surface);
}


Sprite::~Sprite()
{
	if (surface != nullptr)
	{
		SDL_FreeSurface(surface);
	}

	if (texture != nullptr)
	{
		SDL_DestroyTexture(texture);
	}
}