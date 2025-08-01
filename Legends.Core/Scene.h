#pragma once
#include <SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "GameObject.h"
#include "SceneLayer.h"
class GameLoop;

using namespace GameObjects;

class Scene
{
public:
	Scene(std::string name);
    ~Scene();
	void update();
	void render();
	void addObject(GameObject* object);
	std::vector<GameObject*> gameObjects;
	SDL_Texture* sceneTexture;

	std::map<std::string, SceneLayer*> layers = { 
		{"default", new SceneLayer()}
	};
	std::string name;
};