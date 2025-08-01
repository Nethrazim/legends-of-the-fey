
#include "GameSystem.h"

void GameSystem::init()
{

	windowManager.setWindowDimensions(width, height);
	windowManager.setFullScreenMode();
	windowManager.initSDL();
	windowManager.createWindow();

	gameRenderer.createRenderer(windowManager.getWindow());
}

void GameSystem::start()
{
	gameRenderer.start();
}

void GameSystem::prepareScene()
{
	Scene* scene = new Scene("defaut");

	//GameObjects
	GameObject* gameObject = new GameObject();
	gameObject->transform.x = 50;
	gameObject->transform.y = 50;
	gameObject->sprite.loadTexture("", "hello_world.bmp");
	
	GameObject* gameObject2 = new GameObject();
	gameObject2->layer = "enemies";
	gameObject2->transform.x = 150;
	gameObject2->transform.y = 150;
	gameObject2->sprite.loadTexture("", "hello_world.bmp");


	scene->addObject(gameObject);
	scene->addObject(gameObject2);
	SceneManager::addScene(scene);
}