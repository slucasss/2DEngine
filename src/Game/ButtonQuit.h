#pragma once
#include <Engine2d/Engine2d.h>

class ButtonQuit : public AButtonCircle
{
	Text* m_text;

public :
	ButtonQuit(Vector2f _coor, float _radius = 25);

	void Action()override;

	void update(float _deltaTime)override;

	void Draw(Window* window) override;


	~ButtonQuit();
};


