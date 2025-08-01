#include "GameObject.h"

GameObjects::GameObject::GameObject()
{
}

void GameObjects::GameObject::update()
{
	transform.x++;
}

GameObjects::GameObject::~GameObject()
{
}