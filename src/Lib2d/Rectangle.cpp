#include "Rectangle.h"

Rectangle::Rectangle(Vector2f coor, float widht, float height): Geometry(coor), m_height(height), m_widht(widht){
	SDL_FRect r(coor.GetX(), coor.GetY(), widht, height);
	m_rect = r;
}

void Rectangle::Draw(Window* window){
	SDL_RenderRect(window->m_renderer, &m_rect);
}

void Rectangle::SetCoordinates(Vector2f coor){
	Transformable::SetCoordinates(coor);
	m_rect.x = coor.GetX();
	m_rect.y = coor.GetY();
}

bool Rectangle::Inside(Vector2f _coor)
{
	if (_coor.GetX() >= m_rect.x && _coor.GetX() <= m_rect.x + m_rect.w &&
		_coor.GetY() >= m_rect.y && _coor.GetY() <= m_rect.y + m_rect.h)
	{
		return true;
	}
	return false;
}

void* Rectangle::GetRect(){
	return &m_rect;
}

float Rectangle::GetWidth()
{
	return m_widht;
}

float Rectangle::GetHeight()
{
	return m_height;
}
