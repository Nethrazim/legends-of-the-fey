#pragma once
#include <map>
#include <string>
#include <SDL2/SDL_surface.h>
#include "AssetsManager.h"

using namespace std;

namespace LegendsCore
{
	namespace Assets
	{
		class AssetsManager;

		class BaseAssetsLoader
		{
		private:
			AssetsManager* assetsManager = nullptr;
		public:
			virtual void Load(std::string path, std::string fileName, SDL_Surface*& imgSurface) = 0;
			virtual SDL_Surface* Load(std::string fullPath) = 0;
			AssetsManager* getAssetsManager();
			void setAssetsManagerInstance(AssetsManager* manager);
		};
	}
}


