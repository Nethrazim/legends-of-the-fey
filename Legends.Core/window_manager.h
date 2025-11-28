#pragma once

#include <SDL2/SDL.h>

class WindowManager
{
public:
	WindowManager();
	WindowManager(int width, int height);
	void setWindowDimensions(int width, int height);
	bool initSDL();
	bool createWindow();
	void setOpenGL(int glMajor, int glMinor, bool coreProfile, bool vsync);
	bool isOpenGLEnabled();
	void setFullScreenMode();
	void setFullScreenDesktopMode();
	void setWindowMode();

	void destroyWindow();

	static SDL_Window* getWindow();
	
private:
	int _screenWidth;
	int _screenHeight;
	
	int glMajor;
	int glMinor;
	bool coreProfile;
	bool vsync;

	SDL_WindowFlags _windowMode;

	static SDL_Window* window_;
};

