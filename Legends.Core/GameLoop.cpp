#include "GameLoop.h"
#include <stdio.h>
#include <iostream>

SDL_Renderer* GameLoop::renderer = nullptr;

GameLoop::GameLoop(): window(nullptr), isRunning(false) {}

void GameLoop::createRenderer(SDL_Window* window)
{
	this->window = window;

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (!renderer)
	{
		std::cerr << "Renderer Error: " << SDL_GetError() << std::endl;
	}
}

bool GameLoop::start()
{
	if (window == nullptr)
	{
		printf("SDL Window not set.");
		return false;
	}

	if (renderer == nullptr)
	{
		printf("SDL Renderer not set");
		return false;
	}

	loop();
}

void GameLoop::loop()
{
	isRunning = true;

	while (isRunning)
	{
		handleEvents();
		update();
		render();
		SDL_Delay(16);
	}

	clean();
}

void GameLoop::handleEvents() {

	if (inputManager.running())
	{
		inputManager.pollEvents();
		if (inputManager.getInputState().isKeyUp(SDLK_ESCAPE))
		{
			isRunning = false;
		}
	}
}

void GameLoop::update() {
	SceneManager::currentScene()->update();
}

void GameLoop::render() {
	SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
	SDL_RenderClear(renderer);
	SceneManager::currentScene()->render();
	SDL_RenderPresent(renderer);
}

void GameLoop::clean()
{
	SDL_DestroyRenderer(renderer);
}