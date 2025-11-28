#pragma once
#include "input_state.h"

class InputManager
{
public:
	InputManager();
	void pollEvents();
	const InputState& getInputState() const;
	bool running() const;
	int mouseX, mouseY;
private:
	SDL_Event event;
	InputState inputState;
	bool isRunning = true;
};

