#include "img_loader.h"
#include "assets_manager.h"

void LegendsCore::Assets::IMGLoader::Load(std::string path, std::string fileName, SDL_Surface*& imgSurface)
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

	if (getAssetsManager()->surfaceExists(file))
	{
		imgSurface = getAssetsManager()->loadedSurfaces[file];
		return;
	}

	imgSurface = IMG_Load(file.c_str());

	getAssetsManager()->addSurface(imgSurface, file);
}

SDL_Surface* LegendsCore::Assets::IMGLoader::Load(std::string fullPath)
{
	if (getAssetsManager()->surfaceExists(fullPath))
	{
		return getAssetsManager()->loadedSurfaces[fullPath];
	}

	SDL_Surface* newSurface = IMG_Load(fullPath.c_str());

	getAssetsManager()->addSurface(newSurface, fullPath);

	return newSurface;
}	