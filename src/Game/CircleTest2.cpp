#include "CircleTest2.h"

CircleTest2::CircleTest2(Vector2f coor) : Entity(coor), Movable(Vector2f(0, 0), Vector2f(200,0)){
	m_circle = new Circle(coor,25);
	Colider::Init<Circle>(coor, 25);

	//m_sprite 
}

void CircleTest2::Draw(Window* window){
	window->ChangeDrawingColor(255, 255, 255, 255);
	m_circle->Draw(window);
	window->ChangeDrawingColor(0, 0, 0, 255);
}

void CircleTest2::update(float deltaTime){
	if (InputManager::GetInstance()->IsDown("n")) {
		SceneManager::GetInstance()->SetCurrentScene(4);
	}

	PhysiqueManager::GetInstance()->Gravity(this, this, deltaTime, 1.61);
	m_circle->SetCoordinates(GetCoordinates());



	if (GetCoordinates().GetY() + 25 > 500) {
		PhysiqueManager::GetInstance()->Bounce(this, Vector2f(0, 1), 0.25);	
		SetCoordinates(Vector2f(GetCoordinates().GetX(), 500 - 25));
	}
	if (GetCoordinates().GetX() + 25 > 1000) {
		PhysiqueManager::GetInstance()->Bounce(this, Vector2f(1, 0), 0.25);
		SetCoordinates(Vector2f(1000 - 25, GetCoordinates().GetY()));

	}
	if (GetCoordinates().GetX() - 25 < 0) {
		PhysiqueManager::GetInstance()->Bounce(this, Vector2f(-1, 0), 0.25);
		SetCoordinates(Vector2f(0 + 25, GetCoordinates().GetY()));

	}

}


