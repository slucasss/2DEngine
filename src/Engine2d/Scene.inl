#pragma once
#include <vector>
#include "Entity.h"
#include "Lib2d/Lib2d.h"

class Scene: public IDrawable{
	
	std::vector<Entity*>m_entities;

public:
	void UpdateAll(float deltaTime) {
		for (Entity* e : m_entities) {
			e->update(deltaTime);
		}
	}
	

	void Draw(Window* window)override {
		for (Entity* e : m_entities) {
			e->Draw(window);
		}
	}

	void AddEntity(Entity* entity) {
		m_entities.push_back(entity);
	}


	template <typename T>
	T* CreateEntity(Vector2f coor) {
		T* entity = new T(coor);
		m_entities.push_back(entity);
		return entity;
	}

	template <typename T>
	T* GetEntity(){
		for (Entity* e : m_entities) {
			T* casted = dynamic_cast<T*>(e);
			if (casted) {
				return casted;
			}
		}
		return nullptr;
		
	}

	template <typename T>
	std::vector<T*> GetAllTEntity() {
		std::vector<T*> entities;
		for (Entity* e : m_entities) {
			T* casted = dynamic_cast<T*>(e);
			if (casted != nullptr) {
				entities.push_back(casted);

			}
		}
		return entities;
	}
};

