#pragma once
#include "Entity.h"
#include "IButton.h"

class AButtonRectangle : public Entity, public IButton
{
	Rectangle* m_rect;

public : 
	AButtonRectangle(Vector2f _coor, float _width, float _height);

	virtual void Draw(Window* _window)override;

	virtual void IsPressed() override;

	virtual void Action()override;
};


