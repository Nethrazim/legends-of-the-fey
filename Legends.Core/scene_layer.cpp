#include "scene_layer.h"
#include <string>

int SceneLayer::rows = 64;
int SceneLayer::cols = 64;

SceneLayer::SceneLayer() {}

SceneLayer::~SceneLayer() 
{
	
}

void SceneLayer::add(GameObject* gameObject)
{
	layer.push_back(gameObject);
}

size_t SceneLayer::size() const {
	return layer.size();
}