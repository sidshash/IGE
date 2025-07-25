#pragma once
#include "../Observer/Observer.h"
#include <vector>
#include <iostream>
class Subject
{
	std::vector<Observer*> observers;
protected:
	void onEvent(Event *e);
	void AddObserver(Observer* o);
	void RemoveObserver(Observer* o);
};

