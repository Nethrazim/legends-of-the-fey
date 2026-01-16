#include "scene.h"
#include "game_loop.h"
#include <SDL2/SDL.h>
#include "window_manager.h"

extern SDL_GLContext context_;

Scene::Scene(std::string name): tileMap(nullptr), sceneTexture(nullptr)
{
	this->name = name;
}

void Scene::addObject(GameObject* gameObject)
{
	gameObjects.push_back(gameObject);
	
	std::map<std::string, SceneLayer*>::iterator it 
		= layers.find(gameObject->layer);
	
	if (it != layers.end())
	{
		it->second->add(gameObject);
	}
	else
	{
		SceneLayer* newLayer = new SceneLayer();
		newLayer->add(gameObject);

		layers.emplace(gameObject->layer, newLayer);
	}
}

void Scene::update()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		(*it)->update();
	}
}

void Scene::render()
{
	for (std::map<std::string, SceneLayer*>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		for (std::vector<GameObject*>::iterator jit = it->second->layer.begin(); jit != it->second->layer.end(); ++jit)
		{
			if ((*jit)->meshRenderer->active)
			{
				(*jit)->render();
			}
		}
	}
}

Scene::~Scene()
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		delete (*it);
	}
}