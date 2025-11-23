#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "assets_manager.h"

using LegendsCore::Assets::AssetsManager;

class SceneDesigner
{
public:
	static AssetsManager assetsManager;
	static void prepareScene();
};

