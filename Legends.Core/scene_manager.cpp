#include "scene_manager.h"

int SceneManager::currentIndex = -1;
std::vector<Scene*>* SceneManager::scenes = new std::vector<Scene*>();

void SceneManager::addScene(Scene* scene)
{
	scenes->push_back(scene);
	currentIndex++;
}

void SceneManager::switchTo(int index)
{
	if (index < 0 || index >= scenes->size())
	{
		std::cerr << "Wrong index switch" << std::endl;
		return;
	}

	currentIndex = index;
	
	return;
}

void SceneManager::removeScene(int index)
{
	if (index >= 0 && index < scenes->size()) {
		scenes->erase(scenes->begin() + index);
	}
}

void SceneManager::removeAll()
{
	scenes->clear();
}

Scene* SceneManager::currentScene()
{
	return (*scenes)[currentIndex];
}