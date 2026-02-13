#pragma once
#include <Lib2d/Lib2d.h>


class Entity : public IDrawable, public Transformable{

public:
	Entity(Vector2f coor);

	virtual void update(float deltaTime);

	virtual void Draw(Window* window) override;  //Dans les objets enfant, du genre player, on poura appeller, dans cette fonction, la fonction draw du sprite associé au player.
	
};

