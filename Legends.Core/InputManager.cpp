#include "InputManager.h"

InputManager::InputManager() 
	: isRunning(true), event(), inputState(), mouseX(0), mouseY(0)
{
}

void InputManager::pollEvents() {
	inputState.reset();

	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		inputState.update(event);

		if (event.type == SDLK_ESCAPE) {
			isRunning = false;
		}
	}

	SDL_GetMouseState(&mouseX, &mouseY);
}

const InputState& InputManager::getInputState() const {
	return inputState;
}

bool InputManager::running() const {
	return isRunning;
}