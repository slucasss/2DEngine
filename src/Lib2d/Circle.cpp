#include"Circle.h"
#include "Calcul.h"

Circle::Circle(Vector2f coor, float radius): Geometry(coor), m_radius(radius){
}

void Circle::Draw(Window* window){

    float pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196442881097566593344612847564823378678316527120190914564856692346034861045432664821339360726;

    float perimeter = 2 *pi;
    float step = perimeter / 30;

    float radius = m_radius;

    Vector2f center = GetCoordinates();

    int lastX = radius * cos(0) + center.GetX();
    int lastY = radius * sin(0) + center.GetY();

    for (int i = 1; i <= 30; i++)
    {
        int currentX = radius * cos(step * i) + center.GetX();
        int currentY = radius * sin(step * i) + center.GetY();

        SDL_RenderLine(window->m_renderer, lastX, lastY, currentX, currentY);

        lastX = currentX;
        lastY = currentY;
    }
}

bool Circle::Inside(Vector2f _coor)
{
    Vector2f center = GetCoordinates();

    float distance = Math::GetDistance(_coor.GetX(), _coor.GetY(), center.GetX(), center.GetY());
    float radius = GetRadius();

    return distance <= radius;
}

float Circle::GetRadius()
{
    return m_radius;
}
