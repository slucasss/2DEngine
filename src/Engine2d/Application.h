#pragma once
#include "Lib2d/Lib2d.h"
#include "SceneManager.h"


//Couleur bleu logo: (17, 34, 58)

class Application
{
	Window* m_window;

	float m_TargetFps;
	float m_TargetDeltaTime;

	static Application* m_instance;

public:
	static Application* GetInstance();

	Application(float fps);

	void Init(const char* name, const char* IconPath, bool fullscreen = true, int widht = 1000, int height = 500);

	void Loop();

	void Shutdown();

	~Application();
};