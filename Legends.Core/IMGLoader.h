#pragma once
#include <string>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_image.h>


#include "BaseAssetsLoader.h"

namespace LegendsCore
{
	namespace Assets	
	{
		class IMGLoader : public BaseAssetsLoader
		{
		public:
			void Load(std::string path, std::string fileName, SDL_Surface*&) override;
			SDL_Surface* Load(std::string fullPath) override;
		};
;	};
};	


