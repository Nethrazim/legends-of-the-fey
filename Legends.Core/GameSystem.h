#pragma once
#include "SDL.h"
#include "WindowManager.h"
#include "GameLoop.h"
#include "AssetsManager.h"
#include "InputManager.h"

using namespace LegendsCore::Assets;

class GameSystem
{

public:
	int width, height;

	WindowManager windowManager;
	GameLoop gameRenderer;
	AssetsManager assetsManager;


	void init();
	void start();
	void prepareScene();
};