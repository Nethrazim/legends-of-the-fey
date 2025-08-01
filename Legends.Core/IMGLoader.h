#pragma once
#include <string>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>

#include "AssetsLoader.h"

namespace LegendsCore
{
	namespace Assets
	{
		class IMGLoader : public AssetsLoader
		{
		public:
			void Load(std::string path, std::string filename, SDL_Surface*&) override;
		};
	}
}


