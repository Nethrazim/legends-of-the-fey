#include "BaseAssetsLoader.h"


LegendsCore::Assets::AssetsManager* LegendsCore::Assets::BaseAssetsLoader::getAssetsManager()
{
	return assetsManager;
}	

void LegendsCore::Assets::BaseAssetsLoader::setAssetsManagerInstance(LegendsCore::Assets::AssetsManager* manager)
{
	assetsManager = manager;
}

