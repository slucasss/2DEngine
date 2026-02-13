#include "SpriteTest.h"

SpriteTest::SpriteTest(Vector2f coor) : Entity(coor), Movable(Vector2f(0, 0), Vector2f(30,0)){
	m_sprite = new Sprite("../../src/Assets/SaumonEngine.jpeg", coor, NULL, new Rectangle(coor, 50, 50));

}

void SpriteTest::Draw(Window* window){
	m_sprite->Draw(window);
}

void SpriteTest::update(float deltaTime){
	if(InputManager::GetInstance()->IsDown("n")){
		SceneManager::GetInstance()->SetCurrentScene(2);
	}
}


