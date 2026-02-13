#pragma once
#include <Engine2d/Engine2d.h>

class SpriteTest: public Entity, public Movable{
	Sprite* m_sprite;

public:
	SpriteTest(Vector2f coor);

	void Draw(Window* window) override;

	void update(float deltaTime) override;

};

