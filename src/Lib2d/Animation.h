#pragma once
#include <SDL3_image/SDL_image.h>
#include "Window.h"
#include "Transformable.h"
#include "IDrawable.h"
#include "AssetManager.h"
#include "Rectangle.h"

class Animation:public Transformable, public IDrawable{

	int m_image;

	int m_frame;
	int m_framePerImage;
	
	IMG_Animation* m_animation;

	Rectangle* m_DstRect;
	SDL_Texture* m_currentTexture;

public:
	Animation(const char* path, int framePerImage, Vector2f coor, Rectangle* DstRect);

	void Animate(Window* window);

	void Draw(Window* window) override;

	void SetCoordinates(Vector2f coo) override;

	Rectangle* GetDstRect();

	void SetDstRect(float x, float y, float h, float w);
};

