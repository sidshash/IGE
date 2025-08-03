#pragma once
#include "../ENGINE_API.h"
#include "Events.h"
#include <cstdint>

struct ENGINE_API Event
{
	EventName name;
	EventType type;
	void* data;
	const KEY GetKey() const;
};

ENGINE_API inline const char* EventNameToString(Event* e);

ENGINE_API inline const char* EventTypeTypeToString(Event* e);

