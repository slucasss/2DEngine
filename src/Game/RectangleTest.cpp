#include "RectangleTest.h"
#include "AudioSystem.h"

RectangleTest::RectangleTest(Vector2f coor, float widht, float height) : Entity(coor), m_widht(widht), m_height(height), Movable(Vector2f(0, 0), Vector2f(0, 0)){
	m_rect = new Rectangle(coor, widht, height);	
	m_fall = false;

}

void RectangleTest::Draw(Window* window){
	window->ChangeDrawingColor(255, 255, 255, 255);
	m_rect->Draw(window);
	window->ChangeDrawingColor(0, 0, 0, 255);
	window->ChangeDrawingColor(0, 0, 0, 255);
}


void RectangleTest::update(float deltaTime) {
	if (InputManager::GetInstance()->IsDown("d")) {
		m_fall = true;
	}
	
	if (m_fall){
		if (GetCoordinates().GetY() + 50 < 500) {
			PhysiqueManager::GetInstance()->Gravity(this, this, deltaTime, 9.81);
		}
		else if (GetCoordinates().GetY() + 50 != 500) {
			SetCoordinates(Vector2f(GetCoordinates().GetX(), 500 - 50));
			m_speed.SetY(0);
		}
		else {
			PhysiqueManager::GetInstance()->Move(this, this, deltaTime);
		}
		m_rect->SetCoordinates(GetCoordinates());
	}
	
}