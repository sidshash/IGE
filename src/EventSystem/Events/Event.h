#pragma once
#include "Events.hpp"
#include <string>

struct Event
{
	Events::EventNames name;
	Events::EventTypes type;
	void* data;
};
inline std::string GetEventName(Event* e) {
	switch (e->name) {
	case Events::KEYPRESS:
		return "Key Press";
	case Events::CREATE_GAME_OBJECT:
		return "Game Object Created";
	}
}
inline std::string GetEventType(Event* e) {
	switch (e->type) {
	case Events::INPUT:
		return "Input";
	case Events::EDITOR:
		return "Editor";
	}
}

