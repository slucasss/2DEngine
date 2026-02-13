#include "ButtonPlay.h"
#include "ButtonQuit.h"
#include "SpriteTest.h"
#include "TextTest.h"

#include "RectangleTest.h"

ButtonPlay::ButtonPlay(Vector2f _coor, float _height, float _width) : AButtonRectangle(_coor, _width, _height){
	m_CurrentStep = 0;
	m_text = new Text(_coor, 255, 255, 255, 255, "Suivant", 30);
}

void ButtonPlay::Action(){
	m_CurrentStep++;
	if (m_CurrentStep == 1) {
		SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<ButtonQuit>(Vector2f(300 ,115));
	}
	else if (m_CurrentStep == 2) {
		SceneManager::GetInstance()->SetCurrentScene(1);
	}
}

void ButtonPlay::update(float _deltaTime){
	IsPressed();
}

void ButtonPlay::Draw(Window* window){
	AButtonRectangle::Draw(window);
	m_text->Draw(window);
}

ButtonPlay::~ButtonPlay() {}
