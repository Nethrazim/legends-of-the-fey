#include "textured_triangle_mesh_renderer.h"
#include "GameObject.h"
#include <glm/gtc/type_ptr.hpp>


TexturedTriangleMeshRenderer::TexturedTriangleMeshRenderer(GameObjectPtr gameObject)
	: BaseMeshRenderer(gameObject)
{
}

TexturedTriangleMeshRenderer::TexturedTriangleMeshRenderer(GameObjectPtr gameObject, float* newVertices, int size)
	: BaseMeshRenderer(gameObject, newVertices, size)
{
}

TexturedTriangleMeshRenderer::~TexturedTriangleMeshRenderer()
{
}

void TexturedTriangleMeshRenderer::createGLProgram(const char* vsSrc, const char* fsSrc)
{
	BaseMeshRenderer::createGLProgram(vsSrc, fsSrc);
}


void TexturedTriangleMeshRenderer::setUpProgramAttributes()
{
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

void TexturedTriangleMeshRenderer::render(int width, int height, SDL_Window* window, SDL_GLContext context)
{
	if (!programCreated) return;
	
	glUseProgram(program);
	GLint uMVP = glGetUniformLocation(program, "uMVP"); // get uniform location
	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));

	GLint uEdgeColor = glGetUniformLocation(program, "edgeColor"); // get uniform location
	glUniform3fv(uEdgeColor, 1, glm::value_ptr(glm::vec3(0, 0, 0.875)));

	GLint uFillColor = glGetUniformLocation(program, "fillColor"); // get uniform location
	glUniform3fv(uFillColor, 1, glm::value_ptr(glm::vec3(0.3, 0.9, 0.2)));


	static float uEdgeWidthValue = 0.1f;
	static bool uEdgeWidthIncreasing = true;


	if (uEdgeWidthIncreasing && uEdgeWidthValue < 0.5f)
	{
		uEdgeWidthValue += 0.05f;
	}
	else if (uEdgeWidthIncreasing && uEdgeWidthIncreasing >= 0.5f)
	{
		uEdgeWidthIncreasing = false;
	}


	if (!uEdgeWidthIncreasing && uEdgeWidthValue > 0.5f)
	{
		uEdgeWidthValue -= 0.05;
	}
	else if (!uEdgeWidthIncreasing && uEdgeWidthValue <= 0.5f)
	{
		uEdgeWidthIncreasing = true;
	}


	GLint uEdgeWidth = glGetUniformLocation(program, "uEdgeWidth");
	glUniform1f(uEdgeWidth, uEdgeWidthValue);


	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glBindVertexArray(0);
	glUseProgram(0);

}
