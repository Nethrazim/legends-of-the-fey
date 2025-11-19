#pragma once
#include <SDL2/SDL.h>
#include "WindowManager.h"
#include "GameLoop.h"
#include "AssetsManager.h"

using namespace LegendsCore::Assets;


class GameSystem
{

public:
	GameSystem();

	int width, height;

	WindowManager windowManager;
	GameLoop gameRenderer;
	AssetsManager* assetsManager;

	void init();
	void start();
};