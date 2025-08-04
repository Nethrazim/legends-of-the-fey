#pragma once
#include <string>
#include <SDL_surface.h>
#include "AssetsLoader.h"

namespace LegendsCore
{
	namespace Assets
	{
		class AssetsManager
		{
		public:
			static void Load(std::string path, std::string file, SDL_Surface*& imgSurface);
		private:
			static AssetsLoader* createFactoryObject(std::string fileName);
			static std::string getExtension(const std::string& fileName);
		};
	};
};


