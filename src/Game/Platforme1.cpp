#include "Platforme1.h"
#include "Platforme1.h"

Platforme1::Platforme1(Vector2f coor) : Entity(coor){
	m_sprite = new Sprite("../../src/Assets/Brick1.png", coor, NULL, new Rectangle(coor, 32, 32));
	Colider::Init<Rectangle>(coor, 32, 32);
}

void Platforme1::Draw(Window* window) {
	m_sprite->Draw(window);
}



