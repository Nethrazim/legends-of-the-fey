#include "Scene.h"
#include "GameLoop.h"

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
	
	SDL_SetRenderTarget(GameLoop::renderer, sceneTexture);
	SDL_SetRenderDrawColor(GameLoop::renderer, 0, 0, 0, 255);
	SDL_RenderClear(GameLoop::renderer);


	if (tileMap)
	{
		int xAnchor = 0;
		int yAnchor = 0;
		int step = 64;
		for (int i = 0; i < tileMap->wTiles; ++i)
		{
			xAnchor = i * step;
			for (int j = 0; j < tileMap->hTiles; ++j)
			{
				yAnchor = j * step;
				GameObject* obj = layers["enemies"]->layer.at(0);
				SDL_Rect rect = {
					xAnchor,
					yAnchor,
					step,
					step
				};

				SDL_RenderCopy(GameLoop::renderer, obj->sprite.texture, NULL, &rect);
			}
		}
	}

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