#pragma once
#include <Core.h>
class Observer
{
	friend class Subject;
protected:
	virtual void onNotify(Event *e) = 0;
};

