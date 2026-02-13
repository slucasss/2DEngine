#pragma once
#include "Lib2d/Lib2d.h"


class Movable{
	friend class PhysiqueManager;

protected:
	Vector2f m_direction;
	Vector2f m_speed;

	bool stillCollidX;
	bool stillCollidY;

public:
	Movable(Vector2f direction, Vector2f speed);

	void MoveVector(Vector2f* coor);
};