#include "SceneDesigner.h"
#include "Camera.h"
extern const char* vertex_triangle_basic_src;
extern const char* fragment_triangle_basic_src;


void SceneDesigner::prepareScene()
{
	Camera::getInstance();

	Scene* scene = new Scene("default");
	/**scene->sceneTexture = SDL_CreateTexture(GameLoop::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 3840, 2160);
	scene->tileMap = new TileMap();
	scene->tileMap->sprite.loadTexture("", "tile_w2.jpg");
	GameObject* map = new GameObject();
	map->layer = "default";
	map->transform.x = 0;
	map->transform.y = 0;
	map->sprite.loadTexture("", "map.png");
	map->sprite.width = 3840;
	map->sprite.height = 2160;

	GameObject* tile = new GameObject();
	tile->layer = "enemies";

	GameObject* gameObject = new GameObject();
	gameObject->layer = "enemies";
	gameObject->transform.x = 50;
	gameObject->transform.y = 50;
	gameObject->sprite.loadTexture("", "tile.jpg");
	gameObject->sprite.width = 64;
	gameObject->sprite.height = 64;
	*/
	GameObject* openGLgameObject = new GameObject();
	openGLgameObject->layer = "enemies";
	openGLgameObject->transform.x = 0;
	openGLgameObject->transform.y = 0;
	openGLgameObject->transform.z = 0;
	openGLgameObject->scale.x = 2;
	openGLgameObject->scale.y = 2;
	openGLgameObject->scale.z = 2;
	float vertices[] = {
		// positions        // colors
		// positions        // colors
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom left (red)
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom right (green)
		 0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // top right (blue)
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f  // top left (yellow)
	};
	unsigned int indices[] = {
		0, 1, 2, // first triangle
		2, 3, 0  // second triangle
	};


	openGLgameObject->meshRenderer->setVertices(vertices, sizeof(vertices) / sizeof(float));
	openGLgameObject->meshRenderer->createGLProgram(vertex_triangle_basic_src, fragment_triangle_basic_src);


	GameObject* openGLgameObject2 = new GameObject();
	openGLgameObject2->layer = "enemies";
	openGLgameObject2->transform.x = 0;
	openGLgameObject2->transform.y = 0;
	openGLgameObject2->transform.z = 0;
	openGLgameObject2->scale.x = 1;
	openGLgameObject2->scale.y = 1;
	openGLgameObject2->scale.z = 1;

	float vertices2[] = {
		// positions        // colors
		-0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f, // bottom left (red)
		 0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, // bottom right (green)
		 0.5f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f, // top right (blue)
		-0.5f,  0.5f, 0.0f,  1.0f, 1.0f, 0.0f  // top left (yellow)
	};

	unsigned int indices2[] = {
		0, 1, 2, // first triangle
	};

	openGLgameObject2->meshRenderer->setVertices(vertices2, sizeof(vertices2) / sizeof(float));
	openGLgameObject2->meshRenderer->createGLProgram(vertex_triangle_basic_src, fragment_triangle_basic_src);

	openGLgameObject->addChild(openGLgameObject2);
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
	scene->addObject(openGLgameObject);
	//scene->addObject(openGLgameObject2);

	SceneManager::addScene(scene);
}