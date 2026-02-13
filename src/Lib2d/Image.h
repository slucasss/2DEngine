#pragma once
#include <SDL3/SDL.h>

class Image{
	SDL_Texture* m_texture;
	
public:
	Image();


	friend class AssetManager;
	friend class Sprite;

};

