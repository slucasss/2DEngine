#include "TextTest.h"

TextTest::TextTest(Vector2f coor) : Entity(coor), Movable(Vector2f(0, 0), Vector2f(0,0)){
	m_text = new Text(coor, 17, 34, 58, 255, "Saumon engine", 40);
}

void TextTest::Draw(Window* window){
	m_text->Draw(window);

}

void TextTest::update(float deltaTime){
}


