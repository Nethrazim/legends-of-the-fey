#pragma once
#include "glad.h"
#include <SDL2/SDL.h>

namespace GameObjects {
	class GameObject;
}

using namespace GameObjects;

using GameObjectPtr = GameObject*;


class BaseMeshRenderer
{ 
public:
	GameObjectPtr gameObject = nullptr;
	BaseMeshRenderer(GameObjectPtr gameObject);
	BaseMeshRenderer(GameObjectPtr gameObject, float* newVertices, int size);

	~BaseMeshRenderer();


	bool active = false;

	void setVertices(float* newVertices, int size);	
	void createGLProgram(const char* vsSrc, const char* fsSrc);
	virtual void render(int width, int height, SDL_Window* window, SDL_GLContext context);

private: 
	bool programCreated = false;
	float* vertices;
	int vertexSize = 0;
	
	unsigned int indices[6] = { 0, 1, 2, 2, 3, 0 };

	GLuint vs = 0;
	GLuint fs = 0;
	GLuint program = 0;
	GLuint vao = 0;
	GLuint vbo = 0;
	GLuint ebo = 0;
	bool cTimeApplied = false;
};

