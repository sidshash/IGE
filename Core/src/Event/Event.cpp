#include "Event.h"

inline const char* EventNameToString(Event* e) {
	switch (e->name) {
	case EventName::KEYPRESS:
		return "Key Press";
	case EventName::CREATE_GAME_OBJECT:
		return "Create Game Object";
	default:
		return "";
	}
}

inline const char* EventTypeTypeToString(Event* e) {
	switch (e->type) {
	case EventType::INPUT:
		return "Input";
	case EventType::EDITOR:
		return "Editor";
	default:
		return "";
	}
}