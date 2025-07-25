#pragma once

enum class InspectableType {
	Gameobject,
	Component
};

class IInspectable {
public:
	virtual InspectableType GetType() const = 0;
};