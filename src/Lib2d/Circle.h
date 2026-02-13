#pragma once
#include "math.h"
#include "Geometry.h"
class Circle: public Geometry{
	float m_radius;

public:
	Circle(Vector2f coor, float radius); //Les coord sont le centre du cercle

	void Draw(Window* window) override;

	bool Inside(Vector2f _coor)override;

	float GetRadius();


};

