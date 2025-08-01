#pragma once
#include <SDL2/SDL_stdinc.h>

class System
{
private:
	System();
	static float deltaTimeValue;

	static Uint64 currentTimeFrame;
	
	class DeltaProxy
	{
	private:
		static const float& ref;

	public:
		operator float() const;
	};

public:
	static Uint64 startTimeFrame;

	static void setCurrentTimeFrame(Uint64 timeElapsed);

	static DeltaProxy deltaTime;
};

#pragma once
