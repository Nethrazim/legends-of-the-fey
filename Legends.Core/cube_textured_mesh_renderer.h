#pragma once
#include "base_mesh_renderer.h"
#include "game_structs.h"
struct TextureData;



class CubeTexturedMeshRenderer : public BaseMeshRenderer
{
public:
	CubeTexturedMeshRenderer(GameObjectPtr gameObject);
	CubeTexturedMeshRenderer(GameObjectPtr gameObject, float* newVertices, int size);
	~CubeTexturedMeshRenderer();

	void createGLProgram(const char* vsSrc, const char* fsSrc) override;
	void setUpProgramAttributes() override;
	void render(int width, int height, SDL_Window* window, SDL_GLContext context) override;
    TextureData* textureData = nullptr;
    GLuint tex;
    const VertexUV cubeVertices[36] = {
        {0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
        { -0.5f, -0.5f, -0.5f,  1.0f, 0.0f}, // bottom-right
        { -0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        {-0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        { 0.5f,  0.5f, -0.5f,  0.0f, 1.0f}, // top-left
        {0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
         // front face (CCW winding)
        {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f}, // bottom-left
        { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f}, // bottom-right
        { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        {-0.5f,  0.5f,  0.5f,  0.0f, 1.0f}, // top-left
        {-0.5f, -0.5f,  0.5f,  0.0f, 0.0f}, // bottom-left
        // left face (CCW)
        { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
        {-0.5f, -0.5f,  0.5f,  1.0f, 0.0f}, // bottom-right
        {-0.5f,  0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        {-0.5f,  0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        {-0.5f,  0.5f, -0.5f,  0.0f, 1.0f}, // top-left
        {-0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
         // right face (CCW)
        { 0.5f, -0.5f,  0.5f,  0.0f, 0.0f}, // bottom-left
        { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f}, // bottom-right
        { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        { 0.5f,  0.5f,  0.5f,  0.0f, 1.0f}, // top-left
        { 0.5f, -0.5f,  0.5f,  0.0f, 0.0f}, // bottom-left
          // bottom face (CCW)      
        { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
        {  0.5f, -0.5f, -0.5f,  1.0f, 0.0f}, // bottom-right
        {   0.5f, -0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        {  0.5f, -0.5f,  0.5f,  1.0f, 1.0f}, // top-right
        { -0.5f, -0.5f,  0.5f,  0.0f, 1.0f}, // top-left
        { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f}, // bottom-left
          // top face (CCW)
        { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f}, // bottom-left
        {  0.5f,  0.5f,  0.5f,  1.0f, 0.0f}, // bottom-right
        {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f}, // top-right
        { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f}, // top-left
        { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f} // bottom-left
    };


};