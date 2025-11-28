#pragma once
#include "scene.h"
#include "scene_manager.h"
#include "assets_manager.h"

using LegendsCore::Assets::AssetsManager;

class SceneDesigner
{
public:
	static AssetsManager assetsManager;
	static void prepareScene();
};

