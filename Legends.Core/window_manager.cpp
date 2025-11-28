#include "window_manager.h"

#include <iostream>
#include "glad.h"
extern SDL_GLContext context_;

SDL_Window* WindowManager::window_ = nullptr;

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
	if (this->isOpenGLEnabled())
	{
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, glMajor);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, glMinor);
		if (coreProfile) {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
		}
		else {
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
		}

		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

		// Enable multisample (change samples value as desired)
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);

	}

	window_ = SDL_CreateWindow("Legends of the Fey", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, _windowMode);

	
	
	if (window_ == NULL)
	{
		printf("ERROR:: Window could not be created!");
		return false;
	}

	if (isOpenGLEnabled())
	{
		context_ = SDL_GL_CreateContext(window_);
		if (!context_)
		{
			std::cerr << "Failed to create OpenGL context: " << SDL_GetError() << std::endl;
			return false;
		}

		if (vsync) {
			if(SDL_GL_SetSwapInterval(1) < 0) {
				std::cerr << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << std::endl;
			}
			else {
				SDL_GL_SetSwapInterval(0);
			}
		}
		else {
			SDL_GL_SetSwapInterval(0);
		}

		int actualMajor = 0, actualMinor = 0;
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &actualMajor);
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &actualMinor);
		std::cout << "Created OpenGL context " << actualMajor << "." << actualMinor << std::endl;

		if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
		{
			std::cerr << "Failed to load OpenGL functions with GLAD\n";
			SDL_GL_DeleteContext(context_);
			context_ = nullptr;
			return false;
		}

		return true;
	}
	
	return true;
}

SDL_Window* WindowManager::getWindow()
{
	return window_;
}

void WindowManager::setOpenGL(int glMajor, int glMinor, bool coreProfile, bool vsync)
{
	this->glMajor = glMajor;
	this->glMinor = glMinor;
	this->coreProfile = coreProfile;
	this->vsync = vsync;

	_windowMode = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | _windowMode);
}

bool WindowManager::isOpenGLEnabled()
{
	return _windowMode & SDL_WINDOW_OPENGL;
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
	SDL_DestroyWindow(window_);

	SDL_Quit();
}