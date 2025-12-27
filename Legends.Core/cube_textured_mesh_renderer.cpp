#include "cube_textured_mesh_renderer.h"
#include "game_structs.h"
#include "game_object.h"
#include <glm/gtc/type_ptr.hpp>

CubeTexturedMeshRenderer::CubeTexturedMeshRenderer(GameObject* gameObject)
	: BaseMeshRenderer(gameObject)
{
}

CubeTexturedMeshRenderer::CubeTexturedMeshRenderer(GameObject* gameObject, float* newVertices, int size)
	: BaseMeshRenderer(gameObject, newVertices, size)
{
}

CubeTexturedMeshRenderer::~CubeTexturedMeshRenderer()
{
}

void CubeTexturedMeshRenderer::createGLProgram(const char* vsSrc, const char* fsSrc)
{
	BaseMeshRenderer::createGLProgram(vsSrc, fsSrc);
}

void CubeTexturedMeshRenderer::setUpProgramAttributes()
{
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 36 * sizeof(VertexUV), cubeVertices, GL_STATIC_DRAW);

	//Position
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexUV), (void*)0);
	glEnableVertexAttribArray(0);
	
	//UV
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(VertexUV), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	textureData = AssetsManager::getInstance()->loadByteArray("tile.jpg");
	
	GLenum fmt = textureData->comp == 4  ? GL_RGBA : GL_RGB;
	
	glGenTextures(1, &tex);

	glBindTexture(GL_TEXTURE_2D, tex);
	glTexImage2D(GL_TEXTURE_2D, 0, fmt, textureData->w, textureData->h, 0, fmt, GL_UNSIGNED_BYTE, textureData->data);
	
	//glGenerateMipmap(GL_TEXTURE_2D);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); // mipmapping improves quality
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


void CubeTexturedMeshRenderer::render(int width, int height, SDL_Window* window, SDL_GLContext context)
{
	if (!programCreated) return;

	glUseProgram(program);
	
	static GLint uMVP = -1;
	
	if (uMVP == -1)
	{
		uMVP = glGetUniformLocation(program, "uMVP"); // get uniform location
	}


	glUniformMatrix4fv(uMVP, 1, GL_FALSE, glm::value_ptr(gameObject->mvpMatrix));

	static GLint uTex = -1;
	
	if (uTex == -1)
	{
		uTex = glGetUniformLocation(program, "uTex");
	}

	glUniform1i(uTex, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, tex);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);


	glUseProgram(0);
}