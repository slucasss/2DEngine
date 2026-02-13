#pragma once
#include <iostream>


class Vector2f
{
	float m_x;
	float m_y;
public:
	Vector2f(float x, float y);

	float GetX();
	float GetY();

	void SetX(float x);
	void SetY(float y);

	Vector2f operator+(Vector2f right);
	Vector2f operator-(Vector2f right);

	Vector2f operator*(Vector2f right);

	float GetLenght();
	Vector2f Normalize();
};





