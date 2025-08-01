#include "SceneLayer.h"

void SceneLayer::add(GameObject* gameObject)
{
	layer.push_back(gameObject);
}

size_t SceneLayer::size() const{
	return layer.size();
}