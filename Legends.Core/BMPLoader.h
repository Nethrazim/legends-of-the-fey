#pragma once
#include <string>
#include "AssetsLoader.h"
#include <SDL2/SDL_surface.h>


namespace LegendsCore
{
	namespace Assets
	{
		class BMPLoader : public AssetsLoader 
		{
		public:
			void Load(std::string path, std::string fileName, SDL_Surface*& imgSurface) override;
		};
	}
}

