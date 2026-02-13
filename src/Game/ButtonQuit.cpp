#include "ButtonQuit.h"
#include "Application.h"

ButtonQuit::ButtonQuit(Vector2f _coor, float _radius) : AButtonCircle(_coor,_radius) {
	m_text = new Text(Vector2f(_coor.GetX()-15, _coor.GetY()-10), 255, 255, 255, 255, "Quit", 20);
}

void ButtonQuit::Action()
{
	Application::GetInstance()->Shutdown();
}

void ButtonQuit::update(float _deltaTime)
{
	IsPressed();
}

void ButtonQuit::Draw(Window* window) {
	AButtonCircle::Draw(window);
	m_text->Draw(window);
}

ButtonQuit::~ButtonQuit()
{}
