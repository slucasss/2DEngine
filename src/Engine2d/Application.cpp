#include "Application.h"
#include "Timer.h"
#include "AudioSystem.h"

Application* Application::m_instance = nullptr;

Application* Application::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Application(60);
	}
	return m_instance;
}

Application::Application(float fps)
{
	m_window = new Window();

	m_TargetFps = fps;
	m_TargetDeltaTime = 1.f / fps;

}


void Application::Init(const char* name, const char* IconPath, bool fullscreen, int widht, int height)
{
	Timer timer;
	Timer CapFps;

	//Init
	m_window->InitWindow(name, fullscreen, widht, height);
	m_window->ChangeIcon(IconPath);

	AudioSystem::Init();
	AudioSystem::PlayMusic("../../src/Assets/Rose.wav", true);

	//Intro
	float time = 0;


	float spFactor = m_window->GetSize().GetX()/ 1250;
	float spSize = 400 * spFactor;

	Sprite sp("../../src/Assets/SaumonEngine.jpeg", Vector2f(500, 500), NULL, new Rectangle(Vector2f((m_window->GetSize().GetX()/2)-spSize/2, (m_window->GetSize().GetY() / 2) - spSize/2), spSize, spSize));

	ColorScreen cs(0, 0, 0, 0);

	int a = 0;
	bool fade = true;
	while (fade) {

		float dt = CapFps.Restart();


		m_window->ChangeDrawingColor(17, 34, 58, 255);
		m_window->Clear();
		sp.Draw(m_window);

		if (time > 1.5) {
			fade = cs.ExitFade(2);
			cs.Draw(m_window);
		}


		m_window->Update();
		



		time = timer.GetTime();
	
		m_window->Wait(m_TargetDeltaTime, dt);
	}

	m_window->ChangeDrawingColor(0, 0, 0, 255);
}

void Application::Loop()
{
	Timer timer;

	while (m_window->GetIsOpen()){
		float dt = timer.Restart();
		m_window->PollEvents();

		Scene* currentScene = SceneManager::GetInstance()->GetCurrentScene();

		m_window->Clear();

		if (currentScene != nullptr)
		{
			currentScene->UpdateAll(dt);
			currentScene->Draw(m_window);
		}

		InputManager::GetInstance()->Update();


		//m_window->ChangeDrawingColor(0, 0, 0, 255);
		m_window->Update();

		//cap fps
		m_window->Wait(m_TargetDeltaTime, dt);

	}
}

void Application::Shutdown()
{
	m_window->SetIsOpen(false);
}

Application::~Application()
{
	delete m_window;
	AudioSystem::Shutdown();
}