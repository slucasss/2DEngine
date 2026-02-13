#include "Sprite.h"

Sprite::Sprite(const char* path, Vector2f coor, Rectangle* SrcRect, Rectangle* DstRect) : Transformable(coor), m_image(AssetManager::GetInstance()->Load(path)), m_SrcRect(SrcRect), m_DstRect(DstRect) {

}

void Sprite::SetImage(Image* image){
	m_image = image;
}

Image* Sprite::GetImage(){
	return m_image;
}

void Sprite::Draw(Window* window){
	SDL_FRect* SrcRect = NULL;
	SDL_FRect* DstRect = NULL;
	if (m_SrcRect != NULL) {
		SrcRect = (SDL_FRect*)m_SrcRect->GetRect();
	}
	if (m_DstRect != NULL) {
		DstRect = (SDL_FRect*)m_DstRect->GetRect();

	}

	if (window->GetData() == -1) {
		SDL_RenderTextureRotated(window->m_renderer, m_image->m_texture, SrcRect, DstRect, 180, NULL, SDL_FLIP_VERTICAL);
	}
	else {
		SDL_RenderTexture(window->m_renderer, m_image->m_texture, SrcRect, DstRect);
	}
	window->SetData(0);
}

void Sprite::SetCoordinates(Vector2f coo){
	m_DstRect->SetCoordinates(coo);
}

Rectangle* Sprite::GetSrcRect(){
	return m_SrcRect;
}

Rectangle* Sprite::GetDstRect(){
	return m_DstRect;
}

void Sprite::SetSrcRect(float x, float y, float h, float w){
	delete m_SrcRect;
	m_SrcRect = new Rectangle(Vector2f(x, y), w, h);
	m_SrcRect->m_height = h;
	m_SrcRect->m_widht = w;

}

void Sprite::SetDstRect(float x, float y, float h, float w) {
	delete m_DstRect;
	m_DstRect = new Rectangle(Vector2f(x, y), w, h);

	m_DstRect->m_height = h;
	m_DstRect->m_widht = w;
}



