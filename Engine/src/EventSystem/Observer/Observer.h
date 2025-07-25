#pragma once
#include "../Events/Event.h"
class Observer
{
	friend class Subject;
protected:
	virtual void onNotify(Event *e) = 0;
};

