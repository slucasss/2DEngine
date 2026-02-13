#include "Ground.h"

Ground::Ground(Vector2f coor): Entity(coor), m_widht(1000), m_height(100){
	Colider::Init<Rectangle>(coor, 1000, 100);
}
