#include "scene_designer.h"
#include "camera.h"
#include "textured_triangle_mesh_renderer.h"
#include "base_mesh_renderer.h"
#include "cube_textured_mesh_renderer.h"

extern const char* vertex_triangle_basic_src;
extern const char* fragment_triangle_basic_src;
extern const char* vertex_triangle_barycentric_src;
extern const char* fragment_triangle_barycentric_src;
extern const char* cube_vertex_shader;
extern const char* cube_fragment_shader;


void SceneDesigner::prepareScene()
{
	Camera::getInstance();

	Scene* scene = new Scene("default");
	/**
	scene->sceneTexture = SDL_CreateTexture(GameLoop::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 3840, 2160);
	scene->tileMap = new TileMap();
	scene->tileMap->sprite.loadTexture("", "tile_w2.jpg");
	*/

	GameObject* openGLgameObject2 = new GameObject();
	openGLgameObject2->layer = "enemies";
	openGLgameObject2->transform.x = 0;
	openGLgameObject2->transform.y = 0;
	openGLgameObject2->transform.z = 0;
	openGLgameObject2->scale.x = 3;
	openGLgameObject2->scale.y = 3;
	openGLgameObject2->scale.z = 3;

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

	//openGLgameObject->addChild(openGLgameObject2);

	GameObject* shieldTriangle = new GameObject();
	shieldTriangle->layer = "enemies";
	shieldTriangle->transform.x = 5;
	shieldTriangle->transform.y = 5;
	shieldTriangle->transform.z = 0;
	shieldTriangle->scale.x = 5;
	shieldTriangle->scale.y = 5;
	shieldTriangle->scale.z = 5;
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


	GameObject* cube = new GameObject();
	cube->layer = "enemies";
	cube->transform.x = 5;
	cube->transform.y = 5;
	cube->transform.z = 0;
	cube->scale.x = 8;
	cube->scale.y = 8;
	cube->scale.z = 8;


	cube->meshRenderer = static_cast<BaseMeshRenderer*>(new CubeTexturedMeshRenderer(cube));
	cube->meshRenderer->createGLProgram(cube_vertex_shader, cube_fragment_shader);

	/**
	GameObject* gameObject2 = new GameObject();
	gameObject2->layer = "enemies";
	gameObject2->transform.x = 150;
	gameObject2->transform.y = 150;
	gameObject2->sprite.loadTexture("", "hello_world.bmp");
	gameObject2->sprite.width = 64;
	gameObject2->sprite.height = 64;

	GameObject* gameObject3 = new GameObject();
	gameObject3->layer = "enemies";
	gameObject3->transform.x = 250;
	gameObject3->transform.y = 250;
	gameObject3->sprite.loadTexture("", "hello_world.bmp");
	gameObject3->sprite.width = 64;
	gameObject3->sprite.height = 64;
	*/
	//scene->addObject(map);
	//scene->addObject(gameObject);
	//scene->addObject(gameObject2);
	//scene->addObject(openGLgameObject);
	//scene->addObject(openGLgameObject2);
	
	//scene->addObject(shieldTriangle);
	//scene->addObject(openGLgameObject2);
	scene->addObject(cube);
	SceneManager::addScene(scene);
}