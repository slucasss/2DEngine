#pragma once
#include <Engine2d/Engine2d.h>

#include "Ground.h"

class CircleTest2: public Entity, public Movable, public Colider, public IDrawable{
	Circle* m_circle;


	float m_widht;
	float m_height;

	//Sprite m_sprite;

public:
	CircleTest2(Vector2f coor);

	void Draw(Window* window) override;

	void update(float deltaTime) override;

};

