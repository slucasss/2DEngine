#pragma once
#include <Engine2d/Engine2d.h>

class Ground: public Entity, public Colider{
	float m_widht;
	float m_height;

public:
	Ground(Vector2f coor);
};

