#include "assets_manager.h"
#include "bmp_loader.h"
#include "img_loader.h"
#include "GameLoop.h"

LegendsCore::Assets::AssetsManager::AssetsManager() : bmpLoader(nullptr), imgLoader(nullptr) {}

LegendsCore::Assets::AssetsManager* LegendsCore::Assets::AssetsManager::instance = nullptr;

LegendsCore::Assets::AssetsManager* LegendsCore::Assets::AssetsManager::getInstance()
{
	if (instance == nullptr)
	{
		instance = new AssetsManager();
	}
	return instance;
}

void LegendsCore::Assets::AssetsManager::Load(std::string path, std::string fileName, SDL_Surface*& imgSurface)
{
	BaseAssetsLoader* assetsLoader = createFactoryObject(fileName);
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

void LegendsCore::Assets::AssetsManager::addSurface(SDL_Surface* surface, const std::string& key)
{
	if (loadedSurfaces.find(key) == loadedSurfaces.end())
	{
		loadedSurfaces[key] = surface;
	}
}

bool LegendsCore::Assets::AssetsManager::surfaceExists(const std::string key)
{
	return loadedSurfaces.find(key) != loadedSurfaces.end();
}

LegendsCore::Assets::BaseAssetsLoader* LegendsCore::Assets::AssetsManager::createFactoryObject(std::string fileName)
{
	std::string extensionType = getExtension(fileName);
	BaseAssetsLoader* loader = nullptr;

	if (extensionType == "bmp")
	{
		if (bmpLoader == nullptr)
		{
			loader = new BMPLoader();
			loader->setAssetsManagerInstance(this);
			
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
			loader->setAssetsManagerInstance(this);
			
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
		bmpLoader = nullptr;
	}

	if(imgLoader != nullptr)
	{
		delete imgLoader;
		imgLoader = nullptr;
	}

	if(loadedSurfaces.size() > 0)
	{
		for (auto& pair : loadedSurfaces)
		{
			if (pair.second != nullptr)
			{
				SDL_FreeSurface(pair.second);
			}
		}
		loadedSurfaces.clear();
	}
}