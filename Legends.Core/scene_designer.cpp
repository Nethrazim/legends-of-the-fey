#include "scene_designer.h"
#include "camera.h"
#include "textured_triangle_mesh_renderer.h"
#include "base_mesh_renderer.h"
#include "cube_textured_mesh_renderer.h"
#include "color_cube_mesh_renderer.h"

extern const char* vertex_triangle_basic_src;
extern const char* fragment_triangle_basic_src;
extern const char* vertex_triangle_barycentric_src;
extern const char* fragment_triangle_barycentric_src;
extern const char* cube_vertex_shader;
extern const char* cube_fragment_shader;
extern const char* colors_vs;
extern const char* colors_fs;

void SceneDesigner::prepareScene()
{
	Camera::getInstance();

	Scene* scene = new Scene("default");
	/**
	scene->sceneTexture = SDL_CreateTexture(GameLoop::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 3840, 2160);
	scene->tileMap = new TileMap();
	scene->tileMap->sprite.loadTexture("", "tile_w2.jpg");
	*/
	/*
	GameObject* openGLgameObject2 = new GameObject();
	openGLgameObject2->layer = "enemies";
	openGLgameObject2->transform.set(0, 0, 0);
	openGLgameObject2->scale.set(3, 3, 3);

	float vertices2[] = {
		// positions        // colors
		0.0f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // A
		-0.5f,-0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // B
		0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // C
	};

	unsigned int indices2[] = {
		0, 1, 2, // first triangle
	};

	openGLgameObject2->meshRenderer = static_cast<BaseMeshRenderer*>(new TexturedTriangleMeshRenderer(openGLgameObject2));
	openGLgameObject2->meshRenderer->setVertices(vertices2, sizeof(vertices2) / sizeof(float));
	openGLgameObject2->meshRenderer->createGLProgram(vertex_triangle_barycentric_src, fragment_triangle_barycentric_src);
	*/
	//openGLgameObject->addChild(openGLgameObject2);
	/*
	GameObject* shieldTriangle = new GameObject();
	shieldTriangle->layer = "enemies";
	shieldTriangle->transform.set(5, 5, 0);
	shieldTriangle->scale.set(5, 5, 5);

	float vertices3[] = {
		// positions        // colors
		// positions        // colors
		0.0f, 0.5f, 0.0f,   1.0f, 0.0f, 0.0f, // A
		-0.5f,-0.5f, 0.0f,   0.0f, 1.0f, 0.0f, // B
		0.5f,-0.5f, 0.0f,   0.0f, 0.0f, 1.0f  // C
	};
	unsigned int indices3[] = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
	};


	shieldTriangle->meshRenderer->setVertices(vertices3, sizeof(vertices3) / sizeof(float));
	shieldTriangle->meshRenderer->createGLProgram(vertex_triangle_barycentric_src, fragment_triangle_barycentric_src);
	*/
	int x_anchor = -40;
	int z_anchor = -5;
	int y_anchor = 5;

	//for(int i = 0; i < 10; ++i)
	//{
		//aux = i < 10 ? aux : -aux;
		//for (int j = 0; j < 10; ++j)
		//{
			GameObject* cube = new GameObject();
			cube->layer = "enemies";
			cube->rotation.set(0, 3, 0);
			cube->transform.set((x_anchor += 5), y_anchor, (z_anchor+=2));
			cube->scale.set(5, 5, 5);

			cube->meshRenderer = static_cast<BaseMeshRenderer*>(new CubeTexturedMeshRenderer(cube));
			cube->meshRenderer->createGLProgram(cube_vertex_shader, cube_fragment_shader);

			
			GameObject* colorCube = new GameObject();
			colorCube->layer = "enemies";
			colorCube->rotation.set(0, 3, 0);
			colorCube->transform.set(10, 5, 0);
			colorCube->scale.set(10, 10, 10);

			colorCube->meshRenderer = static_cast<BaseMeshRenderer*>(new ColorCubeMeshRenderer(colorCube));
			colorCube->meshRenderer->createGLProgram(colors_vs, colors_fs);
			//scene->addObject(shieldTriangle);
			//scene->addObject(openGLgameObject2);
			//scene->addObject(cube);

			scene->addObject(colorCube);
			scene->addObject(cube);
		//}
		//z_anchor = -5;
		//x_anchor = -30;
		//y_anchor = 5;
	//
	SceneManager::addScene(scene);
}