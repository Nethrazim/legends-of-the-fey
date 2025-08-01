#include "BMPLoader.h"

void LegendsCore::Assets::BMPLoader::Load(std::string path, std::string fileName, SDL_Surface*& imgSurface)
{
	std::string file;
	
	if (path.empty())
	{
		file = fileName;
	}
	else
	{
		file = path + "\\" + fileName;
	}
	
	imgSurface = SDL_LoadBMP(file.c_str());
}
