#include "Animation.h"


Animation::Animation(const char* path, int framePerImage, Vector2f coor, Rectangle* DstRect) :Transformable(coor), m_DstRect(DstRect), m_frame(0), m_image(0), m_framePerImage(framePerImage), m_currentTexture(nullptr){
	m_animation = IMG_LoadAnimation(path);
}

void Animation::Animate(Window* window){
	if (m_frame == 0 && m_image == 0) {
		m_currentTexture = SDL_CreateTextureFromSurface(window->m_renderer, m_animation->frames[m_image]);
	}
	if (m_frame >= m_framePerImage) {
		m_image++;
		m_frame = 0;
	}
	else {
		m_frame++;
		return;
	}
	if (m_image == m_animation->count) {
		m_image = 0;
	}
	m_currentTexture = SDL_CreateTextureFromSurface(window->m_renderer, m_animation->frames[m_image]);
}

void Animation::Draw(Window* window){
	SDL_FRect* DstRect = NULL;
	if (m_DstRect != NULL) {
		DstRect = (SDL_FRect*)m_DstRect->GetRect();
	}
	if (window->GetData() == -1) {
		SDL_RenderTextureRotated(window->m_renderer, m_currentTexture, NULL, &(m_DstRect->m_rect), 180, NULL, SDL_FLIP_VERTICAL);
	}
	else {
		SDL_RenderTexture(window->m_renderer, m_currentTexture, NULL, DstRect);
	}
	window->SetData(0);
}

void Animation::SetCoordinates(Vector2f coo)
{
	m_DstRect->SetCoordinates(coo);

}

Rectangle* Animation::GetDstRect()
{
	return m_DstRect;
}

void Animation::SetDstRect(float x, float y, float h, float w){
	delete m_DstRect;
	m_DstRect = new Rectangle(Vector2f(x, y), w, h);

	m_DstRect->m_height = h;
	m_DstRect->m_widht = w;
}
