#pragma once
#include <string>
#include "AssetsLoader.h"
#include "SDL_surface.h"

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


