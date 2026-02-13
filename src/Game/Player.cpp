#include "Player.h"
#include "CircleTest.h"
#include "AudioSystem.h"

Player::Player(Vector2f coor, float widht, float height) : Entity(coor), m_widht(widht), m_height(height), Movable(Vector2f(0, 0), Vector2f(0, 0)), m_jump(0), m_MovingX(false), m_MovingmX(false), OldCoordinates(0, 0){

	Colider::Init<Rectangle>(coor, widht, height);
	
	m_spriteIdle = new Sprite("../../src/Assets/IdlePlayer.png", coor, NULL, new Rectangle(coor, m_widht, m_height));
	m_spriteJump = new Sprite("../../src/Assets/JumpingPlayer.png", coor, NULL, new Rectangle(coor, m_widht, m_height));
	m_spriteRun = new Animation("../../src/Assets/WalkingPlayer.gif", 10, coor, new Rectangle(coor, m_widht, m_height));


}

void Player::Draw(Window* window) {
	if (m_speed.GetX() < 0) {
		window->SetData(-1);
	}
	else {
		window->SetData(0);
	}

	if (m_jump == 1) {
		m_spriteJump->Draw(window);
	}
	else if(m_MovingX || m_MovingmX){
		m_spriteRun->Animate(window);
		m_spriteRun->Draw(window);
	}
	else {
		m_spriteIdle->Draw(window);
	}
}


void Player::update(float deltaTime) {


	bool fall = false;

	//Colisions


	//Collisions sur le sol
	if (GetCoordinates().GetY() + 64 < 430) {
		fall = true;
	}
	else if (GetCoordinates().GetY() + 64 != 430) {
		SetCoordinates(Vector2f(GetCoordinates().GetX(), 430 - 64));
		m_speed.SetY(0);
		m_jump = 0;
	}



	//collisions sur les plateformes
	auto platforms = SceneManager::GetInstance()->GetCurrentScene()->GetAllTEntity<Platforme1>();
	for (Colider* c : platforms) {
		if (dynamic_cast<Colider*>(c)) {
			Geometry* gFirst = this->GetColider();
			Geometry* gSecond = c->GetColider();
			if (ColisionManager::GetInstance()->IsColiding<Geometry, Geometry>(gFirst, gSecond)) {
				if (GetCoordinates().GetY() + m_height > c->GetColider()->GetCoordinates().GetY()){
					SetCoordinates(Vector2f(GetCoordinates().GetX(), c->GetColider()->GetCoordinates().GetY() - m_height));
					m_speed.SetY(0);
					m_jump = 0;
					fall = false;
				}
			}
		}
	}



	

	//Gere les deplacements en fonction de la vitesse, ce qu'il se passe dans le monde
	if (fall == true) {
		PhysiqueManager::GetInstance()->Gravity(this, this, deltaTime, 9.81);
	}
	else {
		PhysiqueManager::GetInstance()->Move(this, this, deltaTime);
	}



	//deplacements avec les touches
	if (InputManager::GetInstance()->IsDown("d") || InputManager::GetInstance()->IsHeld("d")) {
		if (m_speed.GetX() < 0) {
			m_speed.SetX(0);
			m_MovingmX = false;
		}
		m_speed.SetX(150);
		m_MovingX = true;
	}
	else if (m_speed.GetX() > 0 && m_MovingmX == false) {
		m_speed.SetX(m_speed.GetX() - 5);
		if (m_speed.GetX() <= 0) {
			m_speed.SetX(0);
			m_MovingX = false;
		}
	}

	if (InputManager::GetInstance()->IsDown("q") || InputManager::GetInstance()->IsHeld("q")) {
		if (m_speed.GetX() > 0) {
			m_speed.SetX(0);
			m_MovingX = false;
		}

		m_speed.SetX(-150);
		m_MovingmX = true;
	}
	else if (m_speed.GetX() < 0 && m_MovingX == false) {
		m_speed.SetX(m_speed.GetX() + 5);
		if (m_speed.GetX() >= 0) {
			m_speed.SetX(0);
			m_MovingmX = false;
		}
	}

	if (InputManager::GetInstance()->IsDown("space") && m_jump != 1) {
		m_speed.SetY(-500);
		m_jump = 1;

		//AudioSystem::PlaySFX("../../src/Assets/0648.wav");

	}

	if (InputManager::GetInstance()->IsDown("e")) {
		SceneManager::GetInstance()->GetCurrentScene()->CreateEntity<CircleTest>(Vector2f(GetCoordinates().GetX(), GetCoordinates().GetY()));
	}
	Colider::SetColider(Vector2f(GetCoordinates().GetX(), GetCoordinates().GetY()));

	m_spriteIdle->SetCoordinates(GetCoordinates());
	m_spriteRun->SetCoordinates(GetCoordinates());
	m_spriteJump->SetCoordinates(GetCoordinates());
}

