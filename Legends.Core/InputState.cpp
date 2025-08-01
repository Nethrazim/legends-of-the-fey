#include "InputState.h"

void InputState::update(const SDL_Event& event) {
	
	switch (event.type) {
		case SDL_KEYDOWN:
			if (!event.key.repeat)
			{
				pressedKeys.insert(event.key.keysym.sym);
				releasedKeys.erase(event.key.keysym.sym);
			}
			break;

		case SDL_KEYUP:
			{
				pressedKeys.erase(event.key.keysym.sym);
				releasedKeys.insert(event.key.keysym.sym);
			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			pressedMouseButtons.insert(event.button.button);
			releasedMouseButtons.erase(event.button.button);
			break;

		case SDL_MOUSEBUTTONUP:
			pressedMouseButtons.erase(event.button.button);
			releasedMouseButtons.insert(event.button.button);
			break;

		default:
			break;
	}
}

bool InputState::isKeyUp(SDL_Keycode key) const {
	return releasedKeys.find(key) != releasedKeys.end();
}

bool InputState::isKeyDown(SDL_Keycode key) const {
	return pressedKeys.find(key) != pressedKeys.end();
}

bool InputState::isMouseButtonPressed(Uint8 button) const {
	return pressedMouseButtons.find(button) != pressedMouseButtons.end();
}

void InputState::reset() {
	pressedKeys.clear();
	pressedMouseButtons.clear();
}