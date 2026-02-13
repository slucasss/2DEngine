#pragma once
#include "IButton.h"
#include "Entity.h"

class AButtonCircle : public IButton, public Entity
{
	Circle* m_circle;

public :
	AButtonCircle(Vector2f _coor, float _radius = 25);

	virtual void Draw(Window* _window)override;

	virtual void Action() override = 0;

	virtual void IsPressed() override;

};