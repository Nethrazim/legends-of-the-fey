#pragma once
#include "InputManager.h"
#include <SDL.h>

struct SDL_Window;
struct SDL_Rendrer;

class SceneManager;

class GameLoop
{
private:
	SDL_Rect sourceRect = { 0, 0, 800, 600 };

	int offsetCenterX = 300, offsetCenterY = 200;
	int offsetX = 10, offsetY = 10;
	SDL_Window* window;
	InputManager inputManager;
	int windowWidth, windowHeight;

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
	bool shouldRenderTop();
	bool shouldRenderBottom();
	bool shouldRenderRight();
	bool shouldRenderLeft();
};

