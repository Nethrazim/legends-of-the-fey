#include "System.h"


float System::deltaTimeValue = 0.0f;

Uint64 System::currentTimeFrame = 0.0f;

Uint64 System::startTimeFrame = 0.0f;


const float& System::DeltaProxy::ref = System::deltaTimeValue;

System::DeltaProxy System::deltaTime;


System::DeltaProxy::operator float() const {
	return ref;
}

void System::DeltaProxy::operator=(float value)
{
	System::deltaTimeValue = (value - startTimeFrame) / 1000.0f;
}

void System::setCurrentTimeFrame(Uint64 timeElapsed) {
	currentTimeFrame = timeElapsed;
	deltaTimeValue = (currentTimeFrame - startTimeFrame) / 1000.0f;
}

