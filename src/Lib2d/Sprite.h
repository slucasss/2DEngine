#pragma once
#include "Window.h"
#include "Transformable.h"
#include "IDrawable.h"
#include "AssetManager.h"
#include "Rectangle.h"

class Image;


class Sprite: public Transformable, public IDrawable{
	Image* m_image;

	Rectangle* m_SrcRect;
	Rectangle* m_DstRect;

public:
	Sprite(const char* path, Vector2f coor, Rectangle* SrcRect, Rectangle* DstRect);

	void SetImage(Image* image);

	Image* GetImage();

	void Draw(Window* window) override;

	void SetCoordinates(Vector2f coo) override;

	Rectangle* GetSrcRect();
	Rectangle* GetDstRect();

	void SetSrcRect(float x, float y, float h, float w);

	void SetDstRect(float x, float y, float h, float w);


	
};

