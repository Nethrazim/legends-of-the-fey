#pragma once
#include "base_mesh_renderer.h"
#include "game_structs.h"

struct TextureData;


class ColorCubeMeshRenderer : public BaseMeshRenderer
{
public:
    float time = 0.0f;
    ColorCubeMeshRenderer(GameObject* gameObject);
    ColorCubeMeshRenderer(GameObject* gameObject, float* newVertices, int size);
    ~ColorCubeMeshRenderer();

    void createGLProgram(const char* vsSrc, const char* fsSrc) override;
    void setUpProgramAttributes() override;
    void render(int width, int height, SDL_Window* window, SDL_GLContext context) override;

    const VertexUV cubeVertices[36] = {
       // Back face
       { 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f,  0.0f, -1.0f }, // bottom-left
       { -0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f,  0.0f, -1.0f }, // bottom-right
       { -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f }, // top-right
       { -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f,  0.0f, -1.0f }, // top-right
       { 0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f,  0.0f, -1.0f }, // top-left
       { 0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f,  0.0f, -1.0f }, // bottom-left

       // Front face
       { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f }, // bottom-left
       { 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f,  0.0f,  1.0f }, // bottom-right
       { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f }, // top-right
       { 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f,  0.0f,  1.0f }, // top-right
       { -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f,  0.0f,  1.0f }, // top-left
       { -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f,  0.0f,  1.0f }, // bottom-left

       // Left face
       { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f }, // bottom-left
       { -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, -1.0f,  0.0f,  0.0f }, // bottom-right
       { -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f }, // top-right
       { -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, -1.0f,  0.0f,  0.0f }, // top-right
       { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f, -1.0f,  0.0f,  0.0f }, // top-left
       { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f, -1.0f,  0.0f,  0.0f }, // bottom-left

       // Right face
       { 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  1.0f,  0.0f,  0.0f }, // bottom-left
       { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  1.0f,  0.0f,  0.0f }, // bottom-right
       { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  1.0f,  0.0f,  0.0f }, // top-right
       { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  1.0f,  0.0f,  0.0f }, // top-right
       { 0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  1.0f,  0.0f,  0.0f }, // top-left
       { 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  1.0f,  0.0f,  0.0f }, // bottom-left

       // Bottom face
       { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, -1.0f,  0.0f }, // bottom-left
       { 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f, -1.0f,  0.0f }, // bottom-right
       { 0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  0.0f, -1.0f,  0.0f }, // top-right
       { 0.5f, -0.5f,  0.5f,  1.0f, 1.0f,  0.0f, -1.0f,  0.0f }, // top-right
       { -0.5f, -0.5f,  0.5f,  0.0f, 1.0f,  0.0f, -1.0f,  0.0f }, // top-left
       { -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, -1.0f,  0.0f }, // bottom-left

       // Top face
       { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,  0.0f,  1.0f,  0.0f }, // bottom-left
       { 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  0.0f,  1.0f,  0.0f }, // bottom-right
       { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f,  1.0f,  0.0f }, // top-right
       { 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f,  1.0f,  0.0f }, // top-right
       { -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f,  1.0f,  0.0f }, // top-left
       { -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,  0.0f,  1.0f,  0.0f }  // bottom-left
    };
};