#pragma once
#include <Lib2d/Lib2d.h>

class Colider{
	Geometry* m_colider;

public:

	template <typename T>
	void Init(Vector2f coor, float widht, float height = 0) {
		if constexpr (std::is_same_v<T, Circle>) {
			m_colider = new T(coor, widht);
		}
		else if constexpr (std::is_same_v<T, Rectangle>) {
			m_colider = new T(coor, widht, height);
		}
	}

	Geometry* GetColider() {
		return m_colider;
	}

	void SetColider(Vector2f coor) {
		m_colider->SetCoordinates(coor);
	}

	~Colider() {
		delete m_colider;
	}
};

