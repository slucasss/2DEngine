#include "AButtonCircle.h"
#include "InputManager.h"
#include <iostream>

AButtonCircle::AButtonCircle(Vector2f _coor, float _radius) : Entity(_coor)
{
    m_circle = new Circle(_coor, _radius);
}

void AButtonCircle::Draw(Window* _window) 
{
    _window->ChangeDrawingColor(255, 255, 255, 255);
    m_circle->Draw(_window);
    _window->ChangeDrawingColor(0, 0, 0, 255);
}


void AButtonCircle::IsPressed()
{
    InputManager* input = InputManager::GetInstance();

    Vector2f Mouse(input->GetMouseX(), input->GetMouseY());

    bool pressed = input->IsMouseDown(MouseButton::Left);

    if (m_circle->Inside(Mouse) && pressed)
    {
        Action();
    }
}



