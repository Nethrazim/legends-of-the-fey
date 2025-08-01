#pragma once
#include <string>
#include <vector>
#include <memory>
#include <map>

#include "GameObject.h"
#include "SceneLayer.h"

using namespace std;
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
	std::map<std::string, SceneLayer*> layers = { 
		{"default", new SceneLayer()}
	};
	std::string name;
};