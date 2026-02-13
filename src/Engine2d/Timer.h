#pragma once
#include "Lib2d/Lib2d.h"
#include <chrono>

class Timer {
	std::chrono::steady_clock::time_point m_lastTime;
	float m_deltaTime;

public: 
	Timer();

	void Update();

	float GetTime();
	float Restart();
};