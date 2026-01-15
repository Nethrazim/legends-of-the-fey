
#include "game_system.h"

int GameSystem::width = 0;
int GameSystem::height = 0;

GameSystem::GameSystem()  {
	assetsManager = AssetsManager::getInstance();
}

void GameSystem::init()
{

	windowManager.setWindowDimensions(GameSystem::width, GameSystem::height);
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