#pragma once
#include <string>
#include "BaseAssetsLoader.h"
#include <SDL2/SDL_surface.h>


namespace LegendsCore
{
	namespace Assets
	{
		class BMPLoader : public BaseAssetsLoader 
		{
		public:
			void Load(std::string path, std::string fileName, SDL_Surface*& imgSurface) override;
			SDL_Surface* Load(std::string fullPath) override;
		};
	}
}

