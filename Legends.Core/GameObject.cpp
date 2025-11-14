#include "GameObject.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "System.h"


GameObjects::GameObject::GameObject()
	: transform(), rotation(), scale(), sprite(), meshRenderer(nullptr)
{
	meshRenderer = new MeshRenderer(this);
	meshRenderer->active = true;
}

void GameObjects::GameObject::update()
{
	if (this->layer == "enemies")
	{
		transform.x++;
	}

	updateMVP();
}

void GameObjects::GameObject::updateMVP()
{
	float x = 0.1f * sin(System::deltaTime);
	float y = 0.0f;//0.001f * cos(System::deltaTime);
	model = glm::translate(model, glm::vec3(x, y, 0.0f));

	float angle = System::deltaTime * 70.0f;
	model = glm::rotate(model, angle, glm::vec3(0.0f, 1.0f, 0.0f));

	float scaleFactor = 1.0f + 0.01f * sin(System::deltaTime);
	model = glm::scale(model, glm::vec3(scaleFactor, scaleFactor, scaleFactor));
	
	

	glm::mat4 view = glm::lookAt(
		glm::vec3(0.0f, 0.0f, 2.0f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);

	glm::mat4 projection = glm::perspective(
		glm::radians(60.0f),
		800.0f / 600.0f, // width / height
		0.1f,         // near plane
		100.0f        // far plane
	);


	uMVP = projection * view * model;
}

GameObjects::GameObject::~GameObject()
{
	if(meshRenderer)
	{
		delete meshRenderer;
		meshRenderer = nullptr;
	}	
}