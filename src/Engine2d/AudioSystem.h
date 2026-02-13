#pragma once
#include <string>

class AudioSystem
{
public:
	static bool Init();

	static void PlayMusic(const std::string& _path, bool _loop);

	static void PlaySFX(const std::string& _path);

	static void Shutdown();
};
