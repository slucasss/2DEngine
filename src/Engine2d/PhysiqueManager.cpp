#include "PhysiqueManager.h"

PhysiqueManager* PhysiqueManager::Instance = nullptr;

PhysiqueManager* PhysiqueManager::GetInstance(){
	if (Instance == nullptr) {
		Instance = new PhysiqueManager;
	}
	return Instance;
}

void PhysiqueManager::Gravity(Transformable* entity, Movable* move, float DeltaTime, float g) { //Gere le mouvement en focntion de la vitesse et la direction et applique un effet de gravité
	move->m_speed.SetY(move->m_speed.GetY() + ((g * DeltaTime) * 100));
	Move(entity, move, DeltaTime);
}

void PhysiqueManager::Move(Transformable* entity, Movable* move, float DeltaTime) {
	entity->SetCoordinates(Vector2f(entity->GetCoordinates().GetX() + (move->m_speed.GetX() * DeltaTime), entity->GetCoordinates().GetY() + (move->m_speed.GetY() * DeltaTime)));
}

void PhysiqueManager::Bounce(Movable* move, Vector2f WallShape, float restitution){
	Vector2f velocity = move->m_speed;
	float speed = velocity.GetX() * WallShape.GetX() + velocity.GetY() * WallShape.GetY();

	move->m_speed.SetX(velocity.GetX() - WallShape.GetX() * (1 + restitution) * speed);
	move->m_speed.SetY(velocity.GetY() - WallShape.GetY() * (1 + restitution) * speed);
}

//après un rebond / une colision, il faut placer l'objet a la limite du colider, pour eviter que la colision soit reactiver

