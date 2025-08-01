/*This source code copyrighted by Lazy Foo' Productions 2004-2024
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#define SDL_MAIN_HANDLED

#include <stdio.h>
#include "GameSystem.h"
#include "SceneDesigner.h"

using namespace LegendsCore::Assets;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

GameSystem gameSystem;

SDL_GLContext context_;

int main(int argc, char* argv[])
{
	gameSystem.width = SCREEN_WIDTH;
	gameSystem.height = SCREEN_HEIGHT;

	gameSystem.init();
	SceneDesigner::prepareScene();
	gameSystem.start();

	return 0;
}