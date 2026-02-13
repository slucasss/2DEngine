#pragma once
#include <Engine2d/Engine2d.h>
#include "Platforme1.h"
#include "Ground.h"

//Taille sprite = 16 x 32, donc taille = multiple

class Player: public Entity, public Movable, public Colider, public IDrawable{
	Sprite* m_spriteIdle;
	Animation* m_spriteRun;
	Sprite* m_spriteJump;

	float m_widht;
	float m_height;

	
	int m_jump;
	bool m_MovingX;
	bool m_MovingmX;

	Vector2f OldCoordinates;


                      
public:
	Player(Vector2f coor, float widht = 32, float height = 64);

	void Draw(Window* window) override;

	void update(float deltaTime) override;

};

