#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_surface.h>
#include <iostream>
#include <filesystem>
#include <string>

#include "AssetsLoader.h"

class GameLoop;

namespace LegendsCore
{
	namespace Assets
	{
		class BMPLoader;
		class IMGLoader;
		


		class AssetsManager
		{
		public:
			void Load(std::string path, std::string file, SDL_Surface*& imgSurface);
			SDL_Texture* LoadTexture(std::string, std::string file);
			~AssetsManager();
			AssetsManager();

		private:
			AssetsLoader* createFactoryObject(std::string fileName);
			std::string getExtension(const std::string& fileName);
			BMPLoader* bmpLoader;
			IMGLoader* imgLoader;
		};
	};
};