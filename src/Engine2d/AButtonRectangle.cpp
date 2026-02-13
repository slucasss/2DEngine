#include "AButtonRectangle.h"
#include "InputManager.h"

AButtonRectangle::AButtonRectangle(Vector2f _coor, float _width, float _height) : Entity(_coor)
{
    m_rect = new Rectangle(_coor, _width, _height);
}

void AButtonRectangle::Draw(Window* _window) 
{
    _window->ChangeDrawingColor(255, 255, 255, 255);
    m_rect->Draw(_window);
    _window->ChangeDrawingColor(0, 0, 0, 255);
}

void AButtonRectangle::IsPressed()
{
    InputManager* input = InputManager::GetInstance();

    Vector2f Mouse(input->GetMouseX(), input->GetMouseY());

    bool pressed = input->IsMouseDown(MouseButton::Left);

    if (m_rect->Inside(Mouse) && pressed)
    {
        Action();
    }
}

void AButtonRectangle::Action() {}
