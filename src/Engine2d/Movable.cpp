#include "Movable.h"

Movable::Movable(Vector2f direction, Vector2f speed) : m_direction(direction.Normalize()), m_speed(speed), stillCollidX(false), stillCollidY(false){
}

void Movable::MoveVector(Vector2f* coor){
	*coor = *coor + (m_direction * m_speed);
}
