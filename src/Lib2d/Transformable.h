#pragma once
#include "Vector2f.h"

class Transformable
{
private:

	Vector2f m_coordinates;

public:
	Transformable(Vector2f coor);

	Vector2f GetCoordinates();
	virtual void SetCoordinates(Vector2f coo);
	
};



