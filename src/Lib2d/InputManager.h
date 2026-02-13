#pragma once
#include <SDL3/SDL.h>
#include "MouseButton.h"



class InputManager {

	struct State {
		bool isDown;
		bool isHeld;
		bool isUp;
	};

	struct MouseState
	{
		bool isMouseDown;
		bool isMouseHeld;
		bool isMouseUp;
	};

	static InputManager* Instance;

	State m_states[SDL_SCANCODE_COUNT];
	MouseState m_mouseState[3];

	float m_mouseX;
	float m_mouseY;

public:
	static InputManager* GetInstance();

	InputManager();

	void Update();

	void Event(SDL_Event event);

	bool IsDown(const char* key);

	bool IsHeld(const char* key);

	bool IsUp(const char* key);

	int ConvertSDLMouseButton(int _sdlButton);

	bool IsMouseDown(MouseButton _button);
	bool IsMouseHeld(MouseButton _button);
	bool IsMouseUp(MouseButton _button);

	float GetMouseX();
	float GetMouseY();
};
