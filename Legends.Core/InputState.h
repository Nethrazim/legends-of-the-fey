#pragma once
#include <SDL2/SDL.h>
#include <unordered_set>

class InputState
{
public:
	void update(const SDL_Event& event);

	bool isKeyDown(SDL_Keycode key) const;
	bool isKeyUp(SDL_Keycode key) const;

	bool isMouseButtonPressed(Uint8 button) const;
	
	void reset();
private:
	std::unordered_set<SDL_Keycode> pressedKeys;
	std::unordered_set<SDL_Keycode> releasedKeys;

	std::unordered_set<Uint8> pressedMouseButtons;
	std::unordered_set<Uint8> releasedMouseButtons;
};

