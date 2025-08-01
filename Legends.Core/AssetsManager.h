#pragma once
#include <string>
#include <SDL_surface.h>
#include "AssetsLoader.h"
#include "BMPLoader.h"

namespace LegendsCore
{
	namespace Assets
	{
		class AssetsManager
		{
		public:
			void Load(std::string path, std::string file, SDL_Surface*& imgSurface);
			~AssetsManager();
			AssetsManager();

		private:
			AssetsLoader* createFactoryObject(std::string fileName);
			std::string getExtension(const std::string& fileName);
			BMPLoader* bmpLoader;
		};
	};
};