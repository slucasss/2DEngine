#pragma once
#include <Engine2d/Engine2d.h>

class TextTest: public Entity, public Movable{
	Text* m_text;

public:
	TextTest(Vector2f coor);

	void Draw(Window* window) override;

	void update(float deltaTime) override;

};

