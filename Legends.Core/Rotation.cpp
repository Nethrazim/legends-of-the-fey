#include "Rotation.h"

void GameObjects::Rotation::set(float rotationX, float rotationY, float rotationZ)
{
	this->rotation.x = rotationX;
	this->rotation.y = rotationY;
	this->rotation.z = rotationZ;
}

void GameObjects::Rotation::set(glm::vec3 rotation)
{								
	this->rotation = rotation;
}

void GameObjects::Rotation::setX(float rotationX)
{
	this->rotation.x = rotationX;
}

void GameObjects::Rotation::setY(float rotationY)
{
	this->rotation.y = rotationY;
}

void GameObjects::Rotation::setZ(float rotationZ)
{
	this->rotation.z = rotationZ;
}