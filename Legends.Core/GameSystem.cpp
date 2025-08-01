
#include "GameSystem.h"

GameSystem::GameSystem() : width(0), height(0) {}

void GameSystem::init()
{

	windowManager.setWindowDimensions(width, height);
	windowManager.setWindowMode();
	windowManager.initSDL();
	windowManager.setOpenGL(4, 1, true, true);
	windowManager.createWindow();
	gameRenderer.window = windowManager.getWindow();
	//gameRenderer.createRenderer(windowManager.getWindow());
}

void GameSystem::start()
{
	gameRenderer.start();
}