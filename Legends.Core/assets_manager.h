#pragma once
#include <filesystem>
#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <iostream>

#include "base_assets_loader.h"

class GameLoop;

namespace LegendsCore
{
	namespace Assets
	{
		class BMPLoader;
		class IMGLoader;
		class BaseAssetsLoader;

		class AssetsManager
		{
		public:
			void Load(std::string path, std::string file, SDL_Surface*& imgSurface);
			SDL_Texture* LoadTexture(std::string, std::string file);
			
			~AssetsManager();
			
			static AssetsManager* getInstance();

			void addSurface(SDL_Surface* surface, const std::string& key);
			bool surfaceExists(const std::string key);

			std::map<std::string, SDL_Surface*> loadedSurfaces;
		private:
			BaseAssetsLoader* createFactoryObject(std::string fileName);
			AssetsManager();
			static AssetsManager* instance;

			std::string getExtension(const std::string& fileName);
			
			BMPLoader* bmpLoader;
			IMGLoader* imgLoader;

		};
	};
};