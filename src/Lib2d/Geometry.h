#pragma once
#include <SDL3/SDL.h>
#include "Transformable.h"
#include "IDrawable.h"



class Geometry : public Transformable, public IDrawable {
public:
	Geometry(Vector2f coor);

	virtual void Draw(Window* window) override;

	virtual bool Inside(Vector2f _coor) = 0;

};

