#include "GameObject.h"


GameObjects::GameObject::~GameObject()
{
	if (transform != nullptr)
	{
		delete transform;
	}

	if (rotation != nullptr)
	{
		delete rotation;
	}

	if (scale != nullptr)
	{
		delete scale;
	}
}