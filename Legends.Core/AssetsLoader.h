#pragma once
#include <string>
#include <SDL_surface.h>

namespace LegendsCore
{
	namespace Assets
	{
		class AssetsLoader
		{
		public:
			virtual void Load(std::string path, std::string fileName, SDL_Surface*& imgSurface) = 0;
		};
	}
}


