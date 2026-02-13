#pragma once
#include "Movable.h"


class PhysiqueManager{
	static PhysiqueManager* Instance;
	
public:
	static PhysiqueManager* GetInstance();

	void Gravity(Transformable* entity , Movable* move, float DeltaTime, float g);

	void Move(Transformable* entity, Movable* move, float DeltaTime);

	void Bounce(Movable* move, Vector2f WallShape, float restitution = 0.7);
};

