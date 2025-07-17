#pragma once
#include "../Observer/Observer.h"
#include <vector>
#include <iostream>
#include "../../Logger/Logger.h"
class Subject
{
	std::vector<Observer*> observers;
protected:
	void onEvent(Event *e);
	void AddObserver(Observer* o);
	void RemoveObserver(Observer* o);
};

