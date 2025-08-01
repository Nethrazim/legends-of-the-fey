#pragma once
#include <vector>
#include <memory>
#include "Scene.h"

class SceneManager
{
private:
	static std::vector<Scene*>* scenes;
	static int currentIndex;

public:
	static void addScene(Scene* scene);
	static void switchTo(int index);
	static void removeScene(int index);
	static void removeAll();
	static Scene* currentScene();
};

