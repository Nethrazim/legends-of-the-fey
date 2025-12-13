#include <iostream>
#include "base_mesh_renderer.h"
#include "shader_utils.h"
#include "game_object.h"
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

namespace GameObjects {
	class GameObject;
}

using GameObjectPtr = GameObject*;

BaseMeshRenderer::BaseMeshRenderer(GameObject* gameObject)
	: gameObject(gameObject), vertices(nullptr)
{
}

BaseMeshRenderer::BaseMeshRenderer(GameObject* gameObject, float *newVertices, int size)
	: gameObject(gameObject), vertices(nullptr)
{
	this->setVertices(newVertices, size);	
}

BaseMeshRenderer::~BaseMeshRenderer()
{
	if (vertices)
	{
		delete[] vertices;
		vertices = nullptr;
	}
}

void BaseMeshRenderer::setVertices(float* newVertices, int size)
{
	vertexSize = size;
	if (vertices)
	{
		delete[] vertices;
		vertices = nullptr;
	}

	vertices = new float[size];
	for (int i = 0; i < size; ++i)
	{
		vertices[i] = newVertices[i];
	}
}	


void BaseMeshRenderer::createGLProgram(const char* vsSrc, const char* fsSrc)
{
	vs = glCreateShader(GL_VERTEX_SHADER);
	if (!CompileShader(vs, vsSrc))
	{
		std::cerr << "Failed to compile vertex shader." << std::endl;
		return;
	}

	fs = glCreateShader(GL_FRAGMENT_SHADER);
	if (!CompileShader(fs, fsSrc))
	{
		std::cerr << "Failed to compile fragment shader." << std::endl;
		return;
	}

	program = glCreateProgram();
	
	if (!CreateProgram(program, vs, fs))
	{
		std::cerr << "Failed to create shader program." << std::endl;
		return;
	}

	setUpProgramAttributes();
	
	programCreated = true;
}

void BaseMeshRenderer::setUpProgramAttributes()
{
	// This function can be overridden in derived classes to set up additional attributes if needed.
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	//glGenBuffers(1, &ebo);

	glBindVertexArray(vao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(indices), indices, GL_STATIC_DRAW);

	//layout
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void BaseMeshRenderer::render(int width, int height, SDL_Window* window, SDL_GLContext context)
{
	if (!programCreated) return;

	if (SDL_GL_MakeCurrent(window, context) != 0) {
		std::cerr << "SDL_GL_MakeCurrent failed: " << SDL_GetError() << std::endl;
		return;
	}

	if (gameObject->getChildren()->size() > 0)
	{
		for (auto& child : *gameObject->getChildren())
		{
			if (child->meshRenderer && child->meshRenderer->active)
			{
				child->meshRenderer->render(width, height, window, context);
			}
		}
	}

	glUseProgram(program);
	GLint uMVP = glGetUniformLocation(program, "uMVP"); // get uniform location
	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));

	GLint uEdgeColor = glGetUniformLocation(program, "edgeColor"); // get uniform location
	glUniform3fv(uEdgeColor, 1, glm::value_ptr(glm::vec3(0,0,0.875)));

	GLint uFillColor = glGetUniformLocation(program, "fillColor"); // get uniform location
	glUniform3fv(uFillColor, 1, glm::value_ptr(glm::vec3(0.3,0.9,0.2)));


	static float uEdgeWidthValue = 0.1f;
	static bool uEdgeWidthIncreasing = true;


	if (uEdgeWidthIncreasing && uEdgeWidthValue < 1.0f)
	{
		uEdgeWidthValue += 0.05f;
	}
	else if (uEdgeWidthIncreasing && uEdgeWidthIncreasing >= 1.0f)
	{
		uEdgeWidthIncreasing = false;
	}


	if (!uEdgeWidthIncreasing && uEdgeWidthValue > 0.1f)
	{
		uEdgeWidthValue -= 0.05;
	}
	else if (!uEdgeWidthIncreasing && uEdgeWidthValue <= 0.1f)
	{
		uEdgeWidthIncreasing = true;
	}


	GLint uEdgeWidth = glGetUniformLocation(program, "uEdgeWidth");
	glUniform1f(uEdgeWidth, uEdgeWidthValue);

	//if (!cTimeApplied)
	//{
		//GLint cTime = glGetUniformLocation(program, "cTime");
		//glUniform1f(cTime, static_cast<float>(SDL_GetTicks64()) / 1000.0f);
		//cTimeApplied = true;
	//}


	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
	glUseProgram(0);
}