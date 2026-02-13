#pragma once
#include <Engine2d/Engine2d.h>

class Platforme1: public Entity, public Colider, public IDrawable{
	Sprite* m_sprite;

	float m_widht;
	float m_height;



public:
	Platforme1(Vector2f coor);

	void Draw(Window* window) override;

};

