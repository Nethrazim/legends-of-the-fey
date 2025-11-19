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
	
	if(getAssetsManager()->surfaceExists(file))
	{
		imgSurface = getAssetsManager()->loadedSurfaces[file];
		return;
	}

	imgSurface = SDL_LoadBMP(file.c_str());

	getAssetsManager()->addSurface(imgSurface, file);
}

SDL_Surface* LegendsCore::Assets::BMPLoader::Load(std::string fullPath)
{
	if (getAssetsManager()->surfaceExists(fullPath))
	{
		return getAssetsManager()->loadedSurfaces[fullPath];
	}

	SDL_Surface* newSurface = SDL_LoadBMP(fullPath.c_str());

	getAssetsManager()->addSurface(newSurface, fullPath);

	return newSurface;
}
