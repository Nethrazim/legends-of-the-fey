#include "Transform.h"


void GameObjects::Transform::setX(float x)
{
	this->x = x;
}

void GameObjects::Transform::setY(float y)
{
	this->y = y;
}

void GameObjects::Transform::setZ(float z)
{
	this->z = z;
}

float GameObjects::Transform::getX()
{
	return this->x;
}

float GameObjects::Transform::getY()
{
	return this->y;
}

float GameObjects::Transform::getZ()
{
	return this->z;
}