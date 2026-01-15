/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "game_system.h"
#include "scene_designer.h"

using namespace LegendsCore::Assets;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

GameSystem gameSystem;

SDL_GLContext context_;

int main(int argc, char* argv[])
{
	GameSystem::width = SCREEN_WIDTH;
	GameSystem::height = SCREEN_HEIGHT;

	gameSystem.init();
	SceneDesigner::prepareScene();
	gameSystem.start();

	return 0;
}