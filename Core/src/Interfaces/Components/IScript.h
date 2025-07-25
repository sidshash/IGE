#pragma once
#include "IComponent.h"
#include "../../ENGINE_API.h"
class ENGINE_API IScript: public virtual IComponent
{
public:
	IScript();
	virtual ~IScript();
};

