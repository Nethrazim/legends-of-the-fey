#include "game_object.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"

#include "System.h"
#include "Camera.h"
#include <iostream>


GameObjects::GameObject::GameObject()
	: transform(), rotation(), scale(), sprite(), meshRenderer(nullptr), parent(nullptr)
{
	meshRenderer = new BaseMeshRenderer(this);
	meshRenderer->active = true;
}


void GameObjects::GameObject::addChild(GameObject* child)
{
	children.push_back(child);
	child->parent = this;
}

void GameObjects::GameObject::removeChild(GameObject* child)
{
	auto it = std::find(children.begin(), children.end(), child);
	if (it != children.end())
	{
		children.erase(it);
		child->parent = nullptr;
	}
}


void GameObjects::GameObject::update()
{
	model = glm::mat4(1.0f);

	
	glm::quat rotX = glm::angleAxis(static_cast<float>(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::quat rotY = glm::angleAxis(static_cast<float>(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	glm::quat rotZ = glm::angleAxis(static_cast<float>(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	orientation = rotX * orientation;
	orientation = glm::normalize(orientation);

	orientation = rotY * orientation;
	orientation = glm::normalize(orientation);

	orientation = rotZ * orientation;
	orientation = glm::normalize(orientation);
	


	if (getChildren()->size() > 0)
	{
		for (auto& child : *getChildren())
		{
			child->update();
		}
	}

	if (parent)
	{
		transform.position.x += System::deltaTime * 10.0f;
	}

	script();
	calculateMVP(Camera::getInstance()->view, Camera::getInstance()->projection);
}

void GameObjects::GameObject::script()
{
	
	//default behavior
	
	// 1. Translate
	model = glm::translate(model, glm::vec3(transform.x, transform.y, transform.z));

	// 2. Rotate using the quaternion
	model = model * glm::mat4_cast(orientation);
	//model = glm::rotate(model, static_cast<float>(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	//model = glm::rotate(model, static_cast<float>(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	//model = glm::rotate(model, static_cast<float>(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
	// 
	// 3. Scale
	model = glm::scale(model, scale.scale);
	
	

	//scale
	//model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));
}

glm::mat4 GameObjects::GameObject::getWorldModelMatrix()
{
	if (parent)
	{
		return parent->getWorldModelMatrix() * model;
	}

	return model;
}

void GameObjects::GameObject::calculateMVP(const glm::mat4& view, const glm::mat4& projection)
{
	glm::mat4 model = getWorldModelMatrix();
	mvpMatrix =  projection * view * model;
}

GameObjects::GameObject::~GameObject()
{
	if(meshRenderer)
	{
		delete meshRenderer;
		meshRenderer = nullptr;
	}	
}