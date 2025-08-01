#include "Scene.h"
#include "GameLoop.h"

Scene::Scene(std::string name)
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
	SDL_SetRenderTarget(GameLoop::renderer, sceneTexture);
	SDL_SetRenderDrawColor(GameLoop::renderer, 0, 0, 0, 255);
	SDL_RenderClear(GameLoop::renderer);

	for (std::map<std::string, SceneLayer*>::iterator it = layers.begin(); it != layers.end(); ++it)
	{
		for (std::vector<GameObject*>::iterator jit = it->second->layer.begin(); jit != it->second->layer.end(); ++jit)
		{
			SDL_Rect rect = {
				static_cast<int>((*jit)->transform.x),
				static_cast<int>((*jit)->transform.y),
				(*jit)->sprite.width,
				(*jit)->sprite.height
			};

			SDL_RenderCopy(GameLoop::renderer, (*jit)->sprite.texture, NULL, &rect);
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