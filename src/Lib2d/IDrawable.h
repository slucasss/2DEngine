#pragma once
#include "Window.h"

class IDrawable{
protected:
	virtual void Draw(Window* window) = 0;
};

