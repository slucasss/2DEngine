#include "Background2.h"

Background2::Background2(Vector2f coor): Entity(Vector2f(0, 0)){
	m_sprite = new Sprite("../../src/Assets/Background2.jpg", Vector2f(0, 0), NULL, NULL);
}

void Background2::Draw(Window* window) {
	m_sprite->Draw(window);
}

