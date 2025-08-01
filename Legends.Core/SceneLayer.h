#pragma once
#include <vector>
#include <string>
#include "GameObject.h"
using namespace GameObjects;

class SceneLayer
{
public:
	void add(GameObject* gameObject);

	size_t size() const;

	std::vector<GameObject*> layer;
};

