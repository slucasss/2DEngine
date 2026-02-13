#include "Text.h"



Text::Text(Vector2f coor, int r, int g, int b, int a, const char* text, int size, const char* police ) : Transformable(coor), m_text(text) {
	m_color = { (Uint8)r, (Uint8)g, (Uint8)b, (Uint8)a };

	m_font = TTF_OpenFont(police, size);
	if (!m_font) {
		std::cout << "Police loading failed" << std::endl;
	}

	int lenght = 0;
	while (text[lenght] != '\0') {
		lenght++;
	}

	SDL_Surface* surface = TTF_RenderText_Solid(m_font, m_text, lenght, m_color);
	
	m_texture = SDL_CreateTextureFromSurface(AssetManager::GetInstance()->renderer, surface);
	
	SDL_DestroySurface(surface);


}

Text::~Text(){
	SDL_DestroyTexture(m_texture);
	TTF_CloseFont(m_font);
}

void Text::Draw(Window* window) {
	SDL_FRect dst = { GetCoordinates().GetX(), GetCoordinates().GetY(), 0, 0};
	SDL_GetTextureSize(m_texture, &dst.w, &dst.h);

	SDL_RenderTexture(AssetManager::GetInstance()->renderer, m_texture, NULL, &dst);

}