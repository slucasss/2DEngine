#include "AssetManager.h"

AssetManager* AssetManager::Instance = nullptr;


AssetManager* AssetManager::GetInstance(){
	if (Instance == nullptr) {
		Instance = new AssetManager;
	}
	return Instance;
}

Image* AssetManager::Load(const char* path){
	auto it = m_textures.find(path);

	if (it != m_textures.end())
	{
		return it->second;
	}

	SDL_Surface* surface = IMG_Load(path);

	if (surface == NULL)
	{
		std::cout << "Image not found" << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	SDL_DestroySurface(surface);

	Image* image = new Image();
	image->m_texture = texture;

	m_textures[path] = image;
	return image;
}
