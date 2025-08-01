#pragma once
#include "SDL.h"
#include "SceneManager.h"
#include "InputManager.h"

class GameLoop
{
private:
	SDL_Window* window;
	InputManager inputManager;

	bool isRunning;
	void loop();
	void clean();
	void handleEvents();
	void update();
	void render();

public:
	GameLoop();
	void createRenderer(SDL_Window* window);
	bool start();
	static SDL_Renderer* renderer;
};

