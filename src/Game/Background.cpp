#include "Background.h"

Background::Background(Vector2f coor): Entity(Vector2f(0, 0)){
	m_sprite = new Sprite("../../src/Assets/Background.png", Vector2f(0, 0), NULL, NULL);
}

void Background::Draw(Window* window) {
	m_sprite->Draw(window);
}

