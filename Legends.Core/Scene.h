#pragma once
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "GameObject.h"
#include "SceneLayer.h"
#include "TileMap.h"

class GameLoop;

using namespace GameObjects;

class Scene
{
public:
	Scene(std::string name);
    ~Scene();

	std::string name;
	
	std::vector<GameObject*> gameObjects;
	
	TileMap* tileMap;

	SDL_Texture* sceneTexture;
	
	std::map<std::string, SceneLayer*> layers = {
		{"default", new SceneLayer()}
	};


	void update();
	
	void render();	
	
	void addObject(GameObject* object);
};