#pragma once
#include "game_object_renderer.h"
#include "game_system.h"
#include "game_object.h"
#include <SDL2/SDL.h>

extern SDL_GLContext context_;

namespace GameObjects
{
	GameObjectRenderer::GameObjectRenderer() {}
	
	void GameObjectRenderer::setGameObjectInstance(GameObject* gameObject)
	{
		_gameObject = gameObject;
	}
	
	void GameObjectRenderer::render() {
		if (_gameObject->meshRenderer)
		{
			_gameObject->meshRenderer->render(GameSystem::width, GameSystem::height, WindowManager::getWindow(), context_);
		}
	}
};
