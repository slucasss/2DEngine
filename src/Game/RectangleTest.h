#pragma once
#include <Engine2d/Engine2d.h>

class RectangleTest: public Entity, public Movable{
	Rectangle* m_rect;

	float m_widht;
	float m_height;


	bool m_fall = false;


public:
	RectangleTest(Vector2f coor, float widht = 50, float height = 50);

	void Draw(Window* window) override;

	void update(float deltaTime) override;
};

