#include <iostream>
#include <stdio.h>
#include <SDL2/SDL.h>
#include "game_loop.h"
#include "input_manager.h"
#include "scene_manager.h"
#include "scene.h"

#include "System.h"
extern SDL_GLContext context_;

SDL_Renderer* GameLoop::renderer = nullptr;

GameLoop::GameLoop(): window(nullptr), isRunning(false), windowWidth(0), windowHeight(0) {}

void GameLoop::createRenderer(SDL_Window* window)
{
	this->window = window;
	SDL_GetWindowSize(window, &windowWidth, &windowHeight);

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
	}

	if (SDL_GL_MakeCurrent(window, context_) != 0) {
		std::cerr << "SDL_GL_MakeCurrent failed: " << SDL_GetError() << std::endl;
	}

	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);   // Always use depth testing with culling
	glDepthFunc(GL_LESS);
	glEnable(GL_CULL_FACE);    // enable culling
	glCullFace(GL_BACK);     // Cull back faces
	glFrontFace(GL_CCW);       // CCW is front face


	loop();
}

void GameLoop::loop()
{
	isRunning = true;
	
	while (isRunning)
	{
		System::startTimeFrame = SDL_GetTicks64();
		handleEvents();
		update();
		render();
		SDL_Delay(16);
		System::setCurrentTimeFrame(SDL_GetTicks64());

		std::cout << System::deltaTime << std::endl;
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
	//SDL_SetRenderDrawColor(renderer, 34, 139, 34, 255);
	//SDL_RenderClear(renderer);
	glViewport(0, 0, 800, 600);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	SceneManager::currentScene()->render();

	SDL_GL_SwapWindow(window);
	//
	//SDL_SetRenderTarget(GameLoop::renderer, nullptr);
	/*
	if (shouldRenderRight()) {
		if (sourceRect.x + offsetX < 3000)
		{
			sourceRect.x += offsetX;
		}
	};
	
	if (shouldRenderLeft()) {
		if (sourceRect.x - offsetX > 0)
		{
			sourceRect.x -= offsetX;
		}
	};

	if (shouldRenderBottom()) {
		if ((sourceRect.y + offsetY) < 2000)
		{
			sourceRect.y += offsetY;
		}
	}

	if (shouldRenderTop()) {
		if ((sourceRect.y - offsetY) > 0)
		{
			sourceRect.y -= offsetY;
		}
	}
	*/
	//SDL_RenderCopy(GameLoop::renderer, SceneManager::currentScene()->sceneTexture, &sourceRect, nullptr);
	//SDL_RenderPresent(renderer);
}

bool GameLoop::shouldRenderTop() {
	return inputManager.mouseY < (windowHeight / 2) - offsetCenterY;
}

bool GameLoop::shouldRenderBottom()
{
	return inputManager.mouseY > (windowHeight / 2) + offsetCenterY;
}

bool GameLoop::shouldRenderRight()
{
	return inputManager.mouseX > (windowWidth / 2) + offsetCenterX;
}

bool GameLoop::shouldRenderLeft()
{
	return inputManager.mouseX < (windowWidth / 2) - offsetCenterX;
}

void GameLoop::clean()
{
	SDL_DestroyRenderer(renderer);
}