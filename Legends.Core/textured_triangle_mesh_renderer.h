#pragma once
#include "base_mesh_renderer.h"

class TexturedTriangleMeshRenderer : public BaseMeshRenderer
{
	public:
	TexturedTriangleMeshRenderer(GameObjectPtr gameObject);
	TexturedTriangleMeshRenderer(GameObjectPtr gameObject, float* newVertices, int size);
	~TexturedTriangleMeshRenderer();
	
	void createGLProgram(const char* vsSrc, const char* fsSrc) override;
	void setUpProgramAttributes() override;
	void render(int width, int height, SDL_Window* window, SDL_GLContext context) override;
};

