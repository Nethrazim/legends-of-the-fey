
#include "GameSystem.h"

GameSystem::GameSystem() : width(0), height(0) {}

void GameSystem::init()
{

	windowManager.setWindowDimensions(width, height);
	windowManager.setFullScreenMode();
	windowManager.initSDL();
	windowManager.createWindow();

	gameRenderer.createRenderer(windowManager.getWindow());
}

void GameSystem::start()
{
	gameRenderer.start();
}