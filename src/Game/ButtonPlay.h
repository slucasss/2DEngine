#pragma once
#include <Engine2d/Engine2d.h>


class ButtonPlay : public AButtonRectangle{
	Text* m_text;

	int m_CurrentStep;
public:
	ButtonPlay(Vector2f _coor, float _height = 40, float _width = 100);

	void Action()override;

	void update(float _deltaTime)override;

	void Draw(Window* window) override;

	~ButtonPlay();
};


