#include "color_cube_mesh_renderer.h"
#include "game_structs.h"
#include "game_object.h"
#include <glm/gtc/type_ptr.hpp>
#include "camera.h"

ColorCubeMeshRenderer::ColorCubeMeshRenderer(GameObject* gameObject)
	: BaseMeshRenderer(gameObject) 
{
}

ColorCubeMeshRenderer::ColorCubeMeshRenderer(GameObject* gameObject, float* newVertices, int size)
	: BaseMeshRenderer(gameObject, newVertices, size)
{
}

ColorCubeMeshRenderer::~ColorCubeMeshRenderer()
{
}

void ColorCubeMeshRenderer::createGLProgram(const char* vsSrc, const char* fsSrc)
{
	BaseMeshRenderer::createGLProgram(vsSrc, fsSrc);
}

void ColorCubeMeshRenderer::setUpProgramAttributes()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(VertexUV), cubeVertices, GL_STATIC_DRAW);

	//Position attribute (location 0)
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexUV), (void*)0);
	glEnableVertexAttribArray(0);

	//UV attribute (location 1)
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexUV), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);


	//normal attribute (location =2)
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(VertexUV), (void*)(5 * sizeof(float)));
	glEnableVertexAttribArray(2);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void ColorCubeMeshRenderer::render(int width, int height, SDL_Window* window, SDL_GLContext context)
{
	if (!programCreated) return;

	glUseProgram(program);

	static GLint uMVP = -1;

	if (uMVP == -1) {
		uMVP = glGetUniformLocation(program, "uMVP"); // get uniform location
		glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));
	}
	else
	{
		glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));
	}


	static GLint model = -1;
	if (model == -1)
	{
		model = glGetUniformLocation(program, "model");
		glUniformMatrix4fv(model, 1, GL_FALSE, glm::value_ptr(gameObject->model));
	}

	static GLint view = -1;
	if (view == -1)
	{
		view = glGetUniformLocation(program, "view");
		glUniformMatrix4fv(view, 1, GL_FALSE, glm::value_ptr(Camera::getInstance()->view));
	}

	static GLint projection = -1;
	if (projection == -1)
	{
		projection = glGetUniformLocation(program, "projection");
		glUniformMatrix4fv(projection, 1, GL_FALSE, glm::value_ptr(Camera::getInstance()->projection));
	}

	static GLint lightPos = -1;
	if (lightPos == -1)
	{
		lightPos = glGetUniformLocation(program, "lightPos");
		glUniform3fv(lightPos, 1, glm::value_ptr(Camera::getInstance()->center));
	}
	
	//LIGHT COLOR UNIFORM
	static GLint lightColorLocation = -1;
	if (lightColorLocation == -1) {
		lightColorLocation = glGetUniformLocation(program, "lightColor");
		glm::vec3 lightColorValue(1.0, 1.0f, 1.0f);
		glUniform3fv(lightColorLocation, 1, glm::value_ptr(lightColorValue));
	}
	//else {
		/*time += 0.1f;

		glm::vec3 lightColorValue(
			(std::sin(time) + 1.0f) / 2.0f,
			(std::cos(time) + 1.0f) / 2.0f,
			(std::sin(time + 3.14f / 2.0f) + 1.0f) / 2.0f);

		glUniform3fv(lightColorLocation, 1, glm::value_ptr(lightColorValue));
		*/
	//}
	

	//OBJECT COLOR UNIFORM
	static GLint objectColor = -1;
	if (objectColor == -1)
	{
		objectColor = glGetUniformLocation(program, "objectColor");

		glm::vec3 objectColorValue(0.5f, 0.25f, 1.0f);
		glUniform3fv(objectColor, 1, glm::value_ptr(objectColorValue));
	}
	
	

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);


	glUseProgram(0);
}