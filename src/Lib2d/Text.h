#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Window.h"
#include "Transformable.h"
#include "IDrawable.h"


class Text: public Transformable, public IDrawable {
	
	const char* m_text;
	TTF_Font* m_font;
	SDL_Color m_color;

	SDL_Texture* m_texture;

public:
	Text(Vector2f coor, int r, int g, int b, int a, const char* text, int size, const char* police = "../../src/Assets/PoliceLesMainsENlair.otf");

	void IDrawable::Draw(Window* window) override;

	~Text();
};