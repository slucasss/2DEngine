#pragma once
#include <SDL3/SDL.h>
#include "IDrawable.h"

class ColorScreen: public IDrawable{
	SDL_FColor m_color;
	SDL_Texture* m_texture;

	bool m_change;

public:

	ColorScreen(float r, float g, float b, float a);

	void ChangeR(float r);
	void ChangeG(float g);
	void ChangeB(float b);
	void ChangeA(float a);

	void Draw(Window* window) override;

	void UpdateTextures(Window* window) {

	}

	bool EntranceFade(float d);
	bool ExitFade(float d);
};

