#include "SceneDesigner.h"

void SceneDesigner::prepareScene()
{
	Scene* scene = new Scene("default");
	scene->sceneTexture = SDL_CreateTexture(GameLoop::renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 3840, 2160);
	scene->tileMap = new TileMap();

	GameObject* map = new GameObject();
	map->layer = "default";
	map->transform.x = 0;
	map->transform.y = 0;
	map->sprite.loadTexture("", "map.png");
	map->sprite.width = 3840;
	map->sprite.height = 2160;

	GameObject* gameObject = new GameObject();
	gameObject->layer = "enemies";
	gameObject->transform.x = 50;
	gameObject->transform.y = 50;
	gameObject->sprite.loadTexture("", "tile.jpg");
	gameObject->sprite.width = 64;
	gameObject->sprite.height = 64;

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

	//scene->addObject(map);
	scene->addObject(gameObject);
	scene->addObject(gameObject2);
	scene->addObject(gameObject3);

	SceneManager::addScene(scene);
}