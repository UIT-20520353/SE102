#pragma once

#include "Define.h"

class IRender2D
{
public:
	virtual void Render(float X, float Y, TimeStep elapsed) = 0;
};

