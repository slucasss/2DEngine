#include "Timer.h"

Timer::Timer()
{
	m_lastTime = std::chrono::steady_clock::now();
}

float Timer::GetTime()
{
	auto currentTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsedTime = currentTime - m_lastTime;
	return  elapsedTime.count();
}

float Timer::Restart(){
	auto currentTime = std::chrono::steady_clock::now();
	std::chrono::duration<float> elapsedTime = currentTime - m_lastTime;
	m_lastTime = currentTime;
	return  elapsedTime.count();
}
