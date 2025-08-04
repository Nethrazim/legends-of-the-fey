#include <iostream>
#include <string>
#include <filesystem>

#include "AssetsManager.h"
#include "AssetsLoader.h"
#include "BMPLoader.h"

void LegendsCore::Assets::AssetsManager::Load(std::string path, std::string fileName, SDL_Surface*& imgSurface)
{

	AssetsLoader* assetsLoader = createFactoryObject(fileName);
	assetsLoader->Load(path, fileName, imgSurface);
}


LegendsCore::Assets::AssetsLoader* LegendsCore::Assets::AssetsManager::createFactoryObject(std::string fileName)
{
	std::string extensionType = getExtension(fileName);

	if (extensionType == "bmp")
		return new BMPLoader();

	return nullptr;
}

std::string LegendsCore::Assets::AssetsManager::getExtension(const std::string& fileName)
{
	size_t dotPos = fileName.find_last_of('.');
	if (dotPos != std::string::npos && dotPos != fileName.length() - 1)
	{
		return fileName.substr(dotPos + 1);
	}
	return "";
}
