#include "AssetsManager.h"
#include "BMPLoader.h"
#include "IMGLoader.h"
#include "GameLoop.h"

LegendsCore::Assets::AssetsManager::AssetsManager() : bmpLoader(nullptr), imgLoader(nullptr) {}

void LegendsCore::Assets::AssetsManager::Load(std::string path, std::string fileName, SDL_Surface*& imgSurface)
{
	AssetsLoader* assetsLoader = createFactoryObject(fileName);
	if (!assetsLoader)
	{
		std::cout << "No Loader for that resource" << std::endl;
		return;
	}

	assetsLoader->Load(path, fileName, imgSurface);
}

SDL_Texture* LegendsCore::Assets::AssetsManager::LoadTexture(std::string path, std::string filename)
{
	SDL_Surface* surface = new SDL_Surface();
	this->Load(path, filename, surface);

	if (!surface)
	{
		std::cout << "Resource could not be loaded" << std::endl;
		return nullptr;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(GameLoop::renderer, surface);

	if (!texture)
	{
		std::cout << "Texture could not be created" << std::endl;
		return nullptr;
	}

	return texture;

}


LegendsCore::Assets::AssetsLoader* LegendsCore::Assets::AssetsManager::createFactoryObject(std::string fileName)
{
	std::string extensionType = getExtension(fileName);
	AssetsLoader* loader = nullptr;

	if (extensionType == "bmp")
	{
		if (bmpLoader == nullptr)
		{
			loader = new BMPLoader();
			bmpLoader = static_cast<BMPLoader*>(loader);
			return bmpLoader;
		}
		else
		{
			return bmpLoader;
		}
	}
	else 	
	{
		if (imgLoader == nullptr)
		{
			loader = new IMGLoader();
			imgLoader = static_cast<IMGLoader*>(loader);
			return imgLoader;
		}
		else
		{
			return imgLoader;
		}
	}
		

	return loader;
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

LegendsCore::Assets::AssetsManager::~AssetsManager() 
{	
	if (bmpLoader != nullptr)
	{
		delete bmpLoader;
	}
}