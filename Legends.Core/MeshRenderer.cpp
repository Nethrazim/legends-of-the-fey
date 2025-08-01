#include <iostream>
#include "MeshRenderer.h"
#include "ShaderUtils.h"
#include "GameObject.h"
#include <glm/gtc/type_ptr.hpp>
#include "Camera.h"

namespace GameObjects {
	class GameObject;
}

using GameObjectPtr = GameObject*;

MeshRenderer::MeshRenderer(GameObjectPtr gameObject)
	: gameObject(gameObject), vertices(nullptr)
{
}

MeshRenderer::MeshRenderer(GameObjectPtr gameObject, float *newVertices, int size)
	: gameObject(gameObject), vertices(nullptr)
{
	this->setVertices(newVertices, size);	
}

MeshRenderer::~MeshRenderer()
{
	if (vertices)
	{
		delete[] vertices;
		vertices = nullptr;
	}
}

void MeshRenderer::setVertices(float* newVertices, int size)
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


void MeshRenderer::createGLProgram(const char* vsSrc, const char* fsSrc)
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

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertexSize * sizeof(float), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(indices), indices, GL_STATIC_DRAW);
	
	//layout
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	programCreated = true;
}

void MeshRenderer::render(int width, int height, SDL_Window* window, SDL_GLContext context)
{
	if (!programCreated) return;
	
	if (SDL_GL_MakeCurrent(window, context) != 0) {
		std::cerr << "SDL_GL_MakeCurrent failed: " << SDL_GetError() << std::endl;
		return;
	}

	glUseProgram(program);
	GLint uMVP = glGetUniformLocation(program, "uMVP"); // get uniform location
	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));

	GLint uTime = glGetUniformLocation(program, "uTime");
	glUniform1f(uTime, static_cast<float>(SDL_GetTicks64()) / 1000.0f);

	if (!cTimeApplied)
	{
		GLint cTime = glGetUniformLocation(program, "cTime");
		glUniform1f(cTime, static_cast<float>(SDL_GetTicks64()) / 1000.0f);
		cTimeApplied = true;
	}
	

	glBindVertexArray(vao);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT,0);

	glBindVertexArray(0);
	glUseProgram(0);	
}