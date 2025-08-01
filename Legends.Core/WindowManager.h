#pragma once

#include <SDL.h>

class WindowManager
{
public:
	WindowManager();
	WindowManager(int width, int height);
	void setWindowDimensions(int width, int height);
	bool initSDL();
	bool createWindow();
	void setFullScreenMode();
	void setFullScreenDesktopMode();
	void setWindowMode();

	void destroyWindow();

	SDL_Window* getWindow();
private:
	int _screenWidth;
	int _screenHeight;

	SDL_WindowFlags _windowMode;

	SDL_Window* window = nullptr;
};

