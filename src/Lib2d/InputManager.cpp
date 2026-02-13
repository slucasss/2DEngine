#include "InputManager.h"
#include <iostream>

InputManager* InputManager::Instance = nullptr;

InputManager* InputManager::GetInstance() {
	if (Instance == nullptr) {
		Instance = new InputManager;
	}
	return Instance;
}

InputManager::InputManager()
{
	for (int i = 0; i < SDL_SCANCODE_COUNT; ++i)
	{
		m_states[i].isDown = false;
		m_states[i].isHeld = false;
		m_states[i].isUp = false;
	}

	for (int i = 0; i < 3; ++i)
	{
		m_mouseState[i].isMouseDown = false;
		m_mouseState[i].isMouseHeld = false;
		m_mouseState[i].isMouseUp = false;
	}

	m_mouseX = 0;
	m_mouseY = 0;
}

void InputManager::Update() {
	for (int i = 0; i < SDL_SCANCODE_COUNT; ++i)
	{
		if (m_states[i].isDown) {
			m_states[i].isHeld = true;
		}
		if (m_states[i].isUp) {
			m_states[i].isHeld = false;
		}
		m_states[i].isDown = false;
		m_states[i].isUp = false;
	}

	for (int i = 0; i < 3; i++)
	{
		if (m_mouseState[i].isMouseDown)
		{
			m_mouseState[i].isMouseHeld = true;
		}
		if (m_mouseState[i].isMouseUp)
		{
			m_mouseState[i].isMouseHeld = false;
		}
		m_mouseState[i].isMouseDown = false;
		m_mouseState[i].isMouseUp = false;
	}

	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		SDL_GetMouseState(&m_mouseX, &m_mouseY);

		switch (event.type)
		{
		case SDL_EVENT_KEY_DOWN:
		{
			if (event.key.repeat)
				break;

			m_states[event.key.scancode].isDown = true;

			break;
		}
		case SDL_EVENT_KEY_UP:
		{
			m_states[event.key.scancode].isUp = true;

			break;
		}
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
		{
			int button = ConvertSDLMouseButton(event.button.button);
			if (button != -1)
			{
				m_mouseState[button].isMouseDown = true;
			}

			break;
		}
		case SDL_EVENT_MOUSE_BUTTON_UP:
		{
			int button = ConvertSDLMouseButton(event.button.button);
			if (button != -1)
			{
				m_mouseState[button].isMouseUp = true;
			}

			break;
		}
		}
	}
}

void InputManager::Event(SDL_Event _event)
{
	SDL_GetMouseState(&m_mouseX, &m_mouseY);

	switch (_event.type)
	{
	case SDL_EVENT_KEY_DOWN:
	{
		if (_event.key.repeat)
			break;

		m_states[_event.key.scancode].isDown = true;

		break;
	}
	case SDL_EVENT_KEY_UP:
	{
		m_states[_event.key.scancode].isUp = true;

		break;
	}
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
	{
		int button = ConvertSDLMouseButton(_event.button.button);
		if (button != -1)
		{
			m_mouseState[button].isMouseDown = true;
		}

		break;
	}
	case SDL_EVENT_MOUSE_BUTTON_UP:
	{
		int button = ConvertSDLMouseButton(_event.button.button);
		if (button != -1)
		{
			m_mouseState[button].isMouseUp = true;
		}

		break;
	}
	}
}

bool InputManager::IsDown(const char* key) {

	SDL_Keycode Sdl_Key = SDL_GetKeyFromName(key);

	SDL_Scancode scancode = SDL_GetScancodeFromKey(Sdl_Key, NULL);
	return m_states[scancode].isDown;
}

bool InputManager::IsHeld(const char* key) {

	SDL_Keycode Sdl_Key = SDL_GetKeyFromName(key);

	SDL_Scancode scancode = SDL_GetScancodeFromKey(Sdl_Key, NULL);
	return m_states[scancode].isHeld;
}

bool InputManager::IsUp(const char* key) {

	SDL_Keycode Sdl_Key = SDL_GetKeyFromName(key);

	SDL_Scancode scancode = SDL_GetScancodeFromKey(Sdl_Key, NULL);
	return m_states[scancode].isUp;
}

int InputManager::ConvertSDLMouseButton(int _sdlButton)
{
	switch (_sdlButton)
	{
	case SDL_BUTTON_LEFT:
	{
		return 0;
	}
	case SDL_BUTTON_MIDDLE:
	{
		return 1;
	}
	case SDL_BUTTON_RIGHT:
	{
		return 2;
	}
	default:
	{
		return -1;
	}
	}
}


bool InputManager::IsMouseDown(MouseButton _button)
{
	return m_mouseState[(int)_button].isMouseDown;
}

bool InputManager::IsMouseHeld(MouseButton _button)
{
	return m_mouseState[(int)_button].isMouseHeld;
}

bool InputManager::IsMouseUp(MouseButton _button)
{
	return m_mouseState[(int)_button].isMouseUp;
}

float InputManager::GetMouseX()
{
	return m_mouseX;
}

float InputManager::GetMouseY()
{
	return m_mouseY;
}
