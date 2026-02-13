#include "Vector2f.h"

Vector2f::Vector2f(float x, float y) : m_x(x), m_y(y){}

float Vector2f::GetX(){
	return m_x;
}

float Vector2f::GetY(){
	return m_y;
}

void Vector2f::SetX(float x){
	m_x = x;
}

void Vector2f::SetY(float y){
	m_y = y;
}

Vector2f Vector2f::operator+(Vector2f right) {
	return Vector2f(m_x + right.GetX(), m_y + right.GetY());
}

Vector2f Vector2f::operator-(Vector2f right) {
	return Vector2f(m_x - right.GetX(), m_y - right.GetY());
}

Vector2f Vector2f::operator*(Vector2f right) {
	return Vector2f(m_x * right.GetX(), m_y * right.GetY());
}

float Vector2f::GetLenght(){
	return std::sqrt(std::pow(m_x, 2) + std::pow(m_y, 2));
}

Vector2f Vector2f::Normalize()
{
	float d = GetLenght();
	if (d == 0)
		return Vector2f(0, 0);
	float x = m_x / d;
	float y = m_y / d;

	return Vector2f(x, y);
}



