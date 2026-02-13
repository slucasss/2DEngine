#pragma once
#include <Lib2d/Lib2d.h>
#include <vector>
#include "Colider.inl"


class ColisionManager {
	static ColisionManager* Instance;

public:
	static ColisionManager* GetInstance() {
		if (Instance == nullptr) {
			Instance = new ColisionManager;
		}
		return Instance;
	}


	template <typename T, typename U>
	bool IsColiding(T* firstShape, U* secondeShape) {

		Circle* firstC = dynamic_cast<Circle*>(firstShape);
		Circle* secondeC = dynamic_cast<Circle*>(secondeShape);

		if (firstC && secondeC)
		{
			Vector2f center1 = firstC->GetCoordinates();
			Vector2f center2 = secondeC->GetCoordinates();

			float distance = Math::GetDistance(center1.GetX(), center1.GetY(), center2.GetX(), center2.GetY());
			float radiusDist = firstC->GetRadius() + secondeC->GetRadius();	

			return distance <= radiusDist;
		}

		Rectangle* firstR = dynamic_cast<Rectangle*>(firstShape);
		Rectangle* secondeR = dynamic_cast<Rectangle*>(secondeShape);

		if (firstR && secondeR)
		{
			if (firstR->GetCoordinates().GetX() < secondeR->GetCoordinates().GetX() + secondeR->GetWidth() &&
				firstR->GetCoordinates().GetX() + firstR->GetWidth() > secondeR->GetCoordinates().GetX() &&
				firstR->GetCoordinates().GetY() < secondeR->GetCoordinates().GetY() + secondeR->GetHeight() &&
				firstR->GetCoordinates().GetY() + firstR->GetHeight() > secondeR->GetCoordinates().GetY())
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		if (firstC && firstR)
		{
			return IsCollidingRectCircle(firstC,firstR);
		}

		if (firstC && secondeR)
		{
			return IsCollidingRectCircle(firstC, secondeR);

		}

		if (secondeC && firstR)
		{
			return IsCollidingRectCircle(secondeC, firstR);
		}

		if (secondeC && secondeR)
		{
			return IsCollidingRectCircle(secondeC, secondeR);
		}
		return false;
	}


	bool IsCollidingRectCircle(Circle* cirle, Rectangle* rectangle)
	{
		Vector2f pos = cirle->GetCoordinates();
		float radius = cirle->GetRadius();

		float closestX = std::max(rectangle->GetCoordinates().GetX(), std::min(pos.GetX(), rectangle->GetCoordinates().GetX()+ rectangle->GetWidth()));
		float closestY = std::max(rectangle->GetCoordinates().GetY(), std::min(pos.GetY(), rectangle->GetCoordinates().GetY()+rectangle->GetHeight()));

		float dx = closestX - pos.GetX();
		float dy = closestY - pos.GetY();

		return dx * dx + dy * dy <= radius * radius;
	}

	template <typename T>
	std::vector<Colider*> Colliding(Colider* first, std::vector<T*> second) {

		std::vector<Colider*> colisions;

		for (T* e : second) {
			if (dynamic_cast<Colider*>(e)) {
				Geometry* gFirst = first->GetColider();
				Geometry* gSecond = e->GetColider();

				if (IsColiding(gFirst, gSecond)) {
					colisions.push_back(e);
				}
			}
		}
		return colisions;
	}

};

