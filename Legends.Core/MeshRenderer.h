#pragma once
#include "glad.h"
#include <SDL2/SDL.h>

class MeshRenderer
{ 
public:
	
	MeshRenderer();
	MeshRenderer(float* newVertices, int size);

	~MeshRenderer();


	bool active = false;

	void setVertices(float* newVertices, int size);	
	void createGLProgram(const char* vsSrc, const char* fsSrc);
	void render(int width, int height, SDL_Window* window, SDL_GLContext context);

private: 
	bool programCreated = false;
	float* vertices;
	int vertexSize = 0;
	GLuint vs = 0;
	GLuint fs = 0;
	GLuint program = 0;
	GLuint vao = 0;
	GLuint vbo = 0;
};

