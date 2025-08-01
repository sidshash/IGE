#include "Subject.h"
#include <Core.h>
void Subject::onEvent(Event *e) {
	//std::string eventString[2];
	//Logger::Log(LogLevel::Event, EventNameToString(e), EventTypeTypeToString(e));
	for (Observer *o : observers) {
		if(o)
			o->onNotify(e);
	}
	delete e;
}

void Subject::AddObserver(Observer* o) {
	observers.push_back(o);
}

void Subject::RemoveObserver(Observer* o) {
	observers.erase(
		std::remove(observers.begin(), observers.end(), o),
		observers.end());
}