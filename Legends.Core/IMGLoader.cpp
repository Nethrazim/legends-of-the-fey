#include "IMGLoader.h"


void LegendsCore::Assets::IMGLoader::Load(std::string path, std::string filename, SDL_Surface*& imgSurface)
{
	std::string file;

	if (path.empty())
	{
		file = filename;
	}
	else
	{
		file = path + "\\" + filename;
	}

	imgSurface = IMG_Load(file.c_str());
}