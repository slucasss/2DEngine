#pragma once
#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "Vector2f.h" 
#include "AssetManager.h"

class Window{
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;

	int m_widht;
	int m_height;
	bool m_fullscreen;

	bool m_isOpen;

	int data;

	friend class Sprite;
	friend class text;
	friend class Rectangle;
	friend class Circle;
	friend class ColorScreen;
	friend class Animation;
	friend AssetManager;

public:

	bool InitWindow(const char* name, bool fullscreen, int widht, int height);
	void Clear();
	void Update();

	bool GetIsOpen();
	void PollEvents();

	void ChangeDrawingColor(int r, int g, int b, int a);

	void ChangeIcon(const char* path);

	Vector2f GetSize();

	int GetData();
	void SetData(int d);

	void SetIsOpen(bool _isOpen);

	void Wait(float sec, float _deltaTime);

	~Window();
};

