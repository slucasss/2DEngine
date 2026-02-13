#include "Transformable.h"

Transformable::Transformable(Vector2f coor) : m_coordinates(coor){}

Vector2f Transformable::GetCoordinates()
{
    return m_coordinates;
}

void Transformable::SetCoordinates(Vector2f coo){
    m_coordinates = coo;
}