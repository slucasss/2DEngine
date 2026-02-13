#include "ColorScreen.h"

ColorScreen::ColorScreen(float r, float g, float b, float a): m_color(r, g, b, a), m_texture(nullptr), m_change(false){


}

void ColorScreen::ChangeR(float r){
}

void ColorScreen::ChangeG(float g){
	m_color.g = g;
}

void ColorScreen::ChangeB(float b){
	m_color.b = b;
}

void ColorScreen::ChangeA(float a){
	m_color.a = a;
}

void ColorScreen::Draw(Window* window){
	if (m_texture == nullptr) {
		m_texture = SDL_CreateTexture(window->m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, window->m_widht, window->m_height);
		if (!m_texture) {
			std::cout << "Erreur dans le chargement de la texture ScreenColor" << std::endl;
			return;
		}

		SDL_SetTextureBlendMode(m_texture, SDL_BLENDMODE_BLEND);


		SDL_Texture* previous = SDL_GetRenderTarget(window->m_renderer);


		SDL_SetRenderTarget(window->m_renderer, m_texture);
		SDL_SetRenderDrawColor(window->m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
		SDL_SetRenderDrawBlendMode(window->m_renderer, SDL_BLENDMODE_BLEND);

		SDL_RenderClear(window->m_renderer);

		SDL_SetRenderTarget(window->m_renderer, previous);

	}

	if (m_change) {
		SDL_Texture* previous = SDL_GetRenderTarget(window->m_renderer);

		SDL_SetRenderTarget(window->m_renderer, m_texture);
		SDL_SetRenderDrawBlendMode(window->m_renderer, SDL_BLENDMODE_BLEND);
		SDL_SetRenderDrawColor(window->m_renderer, m_color.r, m_color.g, m_color.b, m_color.a);
		SDL_RenderClear(window->m_renderer);

		SDL_SetRenderTarget(window->m_renderer, previous);
		m_change = false;
	}

	SDL_RenderTexture(window->m_renderer, m_texture, NULL, NULL);

}

bool ColorScreen::EntranceFade(float d){
	if (m_color.a - d > 0) {
		m_color.a = m_color.a - d;
		m_change = true;
		return true;
	}
	return false;

}

bool ColorScreen::ExitFade(float d){
	if (m_color.a + d < 255) {
		m_color.a = m_color.a + d;
		m_change = true;
		return true;
	}
	return false;
}
