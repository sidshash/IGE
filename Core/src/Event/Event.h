#pragma once
#include "../ENGINE_API.h"
#include "Events.h"

struct ENGINE_API Event
{
	EventName name;
	EventType type;
	void* data;
};

ENGINE_API inline const char* EventNameToString(Event* e);

ENGINE_API inline const char* EventTypeTypeToString(Event* e);

