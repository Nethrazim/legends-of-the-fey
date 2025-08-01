#pragma once
#include <iostream>
#include <vector>
#include <memory>
class Scene;

class SceneManager
{
public:
	static void addScene(Scene* scene);
	static void switchTo(int index);
	static void removeScene(int index);
	static void removeAll();
	static Scene* currentScene();

private:
	static std::vector<Scene*>* scenes;
	static int currentIndex;
};

