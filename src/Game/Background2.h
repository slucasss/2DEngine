#pragma once
#include <Engine2d/Engine2d.h>

class Background2: public Entity, public IDrawable{
	Sprite* m_sprite = m_sprite;
public:
	Background2(Vector2f coor);

	void Draw(Window* window) override;

};

