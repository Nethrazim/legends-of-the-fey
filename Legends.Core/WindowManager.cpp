#include "WindowManager.h"
#include <iostream>

WindowManager::WindowManager() {
	_screenWidth = 800;
	_screenHeight = 600;
	_windowMode = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN;
}

WindowManager::WindowManager(int width, int height)
{
	_screenWidth = width;
	_screenHeight = height;
	_windowMode = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN;
}

void WindowManager::setWindowDimensions(int width, int height)
{
	_screenWidth = width;
	_screenHeight = height;
}

bool WindowManager::initSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("ERROR:: SDL could not be initialized");
		return false;
	}

	return true;
}

bool WindowManager::createWindow()
{
	window = SDL_CreateWindow("Legends of the Fey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, _windowMode);
	
	if (window == NULL)
	{
		printf("ERROR:: Window could not be created!");
		return false;
	}

	//screenSurface = SDL_GetWindowSurface(window);
	return true;
}

SDL_Window* WindowManager::getWindow()
{
	return window;
}

void WindowManager::setFullScreenMode()
{
	_windowMode = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN;
}

void WindowManager::setFullScreenDesktopMode()
{
	_windowMode = SDL_WindowFlags::SDL_WINDOW_FULLSCREEN_DESKTOP;
}

void WindowManager::setWindowMode()
{
	_windowMode = SDL_WindowFlags::SDL_WINDOW_SHOWN;
}

void WindowManager::destroyWindow()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}