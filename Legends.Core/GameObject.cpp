#include "GameObject.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "System.h"
#include "Camera.h"


GameObjects::GameObject::GameObject()
	: transform(), rotation(), scale(), sprite(), meshRenderer(nullptr)
{
	meshRenderer = new MeshRenderer(this);
	meshRenderer->active = true;
}


void GameObjects::GameObject::update()
{
	//scale.x += 0.0001f;
	//scale.y += 0.0001f;
	//scale.z += 0.0001f;
	//transform.x = System::deltaTime * 0.05f;
	script();
	calculateMVP(Camera::getInstance()->view, Camera::getInstance()->projection);
}

void GameObjects::GameObject::script()
{
	
	//default behavior
	
	//rotate
	model = glm::rotate(model, rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

	//translate
	model = glm::translate(model, glm::vec3(transform.x, transform.y, transform.z));

	//scale
	model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));
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