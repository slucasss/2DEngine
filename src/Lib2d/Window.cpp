	#include "Window.h"
	#include "InputManager.h"

	bool Window::InitWindow(const char* name, bool fullscreen, int widht = 1000, int height = 500){
		m_widht = widht;
		m_height = height;
		m_fullscreen = fullscreen;

		m_isOpen = true;
		data = 0;
		SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);


		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
		{
			std::cout << "Error SDL2 Initialization : " << SDL_GetError() << std::endl;
			return false;
		}


		m_window = SDL_CreateWindow(name, m_widht, m_height, NULL);
		if (!SDL_SetWindowFullscreen(m_window, fullscreen)) {
			std::cout << "Fullscreen error : " << SDL_GetError() << std::endl;
		}



		if (m_window == nullptr)
		{
			std::cout << "Error window creation";
			return false;
		}
		if (TTF_Init() < 0) {
			SDL_Log("Erreur TTF_Init");
		}
	
		m_renderer = SDL_CreateRenderer(m_window, NULL);

		if (m_renderer == nullptr)
		{
			std::cout << "Error renderer creation" << std::endl;
			return false;
		}

		SDL_GetWindowSize(m_window, &m_widht, &m_height);

		//std::cout << m_widht << " " << m_height;

		AssetManager::GetInstance()->renderer = m_renderer;

		return true;
	}

	void Window::Clear(){
		SDL_RenderClear(m_renderer);
	}

	void Window::Update() {
		SDL_RenderPresent(m_renderer);
	}

	bool Window::GetIsOpen()
	{
		return m_isOpen;
	}

	void Window::PollEvents()
	{
		SDL_Event event;

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_EVENT_QUIT || event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
			{
				m_isOpen = false;
			}

			InputManager::GetInstance()->Event(event);
		}
	}

	void Window::ChangeIcon(const char* path){
		SDL_Surface* icon = IMG_Load(path);

		if (icon == NULL)
		{
			std::cout << "Image not found" << std::endl;
			return;
		}

		SDL_SetWindowIcon(m_window,icon);
	}

	Vector2f Window::GetSize(){
		return Vector2f(m_widht, m_height);
	}

	int Window::GetData(){
		return data;
	}

	void Window::SetData(int d){
		data = d;
	}

	void Window::ChangeDrawingColor(int r, int g, int b, int a) {
		SDL_SetRenderDrawColor(m_renderer, r, g, b, a);
	}

	void Window::SetIsOpen(bool _isOpen){
		m_isOpen = _isOpen;
	}

  void Window::Wait(float sec, float _deltaTime){
    float diff = sec - _deltaTime;
    if (diff > 0){
      SDL_Delay(diff * 1000);
    }
  }

	Window::~Window(){
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}