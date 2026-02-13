#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <map>

#include "Image.h"

class AssetManager{

	static AssetManager* Instance;

	SDL_Renderer* renderer;
	std::map < const char*, Image*> m_textures;

	friend class Window;   //Pour que la window set le renderer
	friend class Text;
public:
	static AssetManager* GetInstance();

	Image* Load(const char* path);
};

