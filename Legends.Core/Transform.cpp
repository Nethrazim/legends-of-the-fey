#include "Transform.h"

GameObjects::Transform::Transform() : x(position.x), y(position.y), z(position.z)
{

}

GameObjects::Transform::Transform(int x, int y, int z) : x(position.x), y(position.y), z(position.z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

void GameObjects::Transform::set(glm::vec3 newPosition)
{
	this->position = newPosition;
}

void GameObjects::Transform::set(float x, float y, float z)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

void GameObjects::Transform::setX(float x)
{
	this->position.x = x;
}

void GameObjects::Transform::setY(float y)
{
	this->position.y = y;
}

void GameObjects::Transform::setZ(float z)
{
	this->position.z = z;
}

float GameObjects::Transform::getX()
{
	return this->position.x;
}

float GameObjects::Transform::getY()
{
	return this->position.y;
}

float GameObjects::Transform::getZ()
{
	return this->position.z;
}