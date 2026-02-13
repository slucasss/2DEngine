#include "Calcul.h"

namespace Math
{
	float GetDistance(float x1, float y1, float x2, float y2)
	{
		float distanceX = (x1 - x2) * (x1 - x2);
		float distanceY = (y1 - y2) * (y1 - y2);
		float distance = sqrt(distanceX + distanceY);

		return distance;
	}

	Vector2f GetDirection(int x1, int y1, int x2, int y2) {
		int transX = x2 - x1;
		int transY = y2 - y1;

		float sqrDist = (transX * transX) + (transY * transY);
		float dist = sqrt(sqrDist);

		return { transX / dist,  transY / dist };
	}
}


