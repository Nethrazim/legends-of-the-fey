#include "GameObject.h"

GameObjects::GameObject::GameObject()
	: transform(), rotation(), scale(), sprite(), meshRenderer()
{
	meshRenderer.active = true;
}

void GameObjects::GameObject::update()
{
	if (this->layer == "enemies")
	{
		transform.x++;
	}
}

GameObjects::GameObject::~GameObject()
{
}