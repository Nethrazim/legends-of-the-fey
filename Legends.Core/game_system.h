#pragma once
#include <SDL2/SDL.h>
#include "window_manager.h"
#include "game_loop.h"
#include "assets_manager.h"

using namespace LegendsCore::Assets;


class GameSystem
{

public:
	GameSystem();

	static int width;
	static int height;

	WindowManager windowManager;
	GameLoop gameRenderer;
	AssetsManager* assetsManager;

	void init();
	void start();
};