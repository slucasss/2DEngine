#pragma once
#include "Geometry.h"



class Rectangle : public Geometry {
	float m_height;
	float m_widht;
	SDL_FRect m_rect;

	friend class Sprite;
	friend class Animation;

public:
	Rectangle(Vector2f coor,float widht, float height);

	void Draw(Window* window) override;

	void SetCoordinates(Vector2f coor) override;

	bool Inside(Vector2f _coor)override;

	void* GetRect();
	float GetWidth();
	float GetHeight();


};

