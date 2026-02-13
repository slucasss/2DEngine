#pragma once
#include <Engine2d/Engine2d.h>

class Background: public Entity, public IDrawable{
	Sprite* m_sprite = m_sprite;
public:
	Background(Vector2f coor);

	void Draw(Window* window) override;

};

