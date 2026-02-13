#include "AudioSystem.h"
#include "../../../lib/Miniaudio/miniaudio.h"
#include <iostream>

static ma_engine m_engine;
static ma_sound m_music;
static bool m_musicLoad = false;

bool AudioSystem::Init()
{
	if (ma_engine_init(nullptr, &m_engine) != MA_SUCCESS)
	{
		return false;
	}

	return true;
}


void AudioSystem::PlayMusic(const std::string& _path, bool _loop)
{
	if (m_musicLoad) //Utile si on veut une autre musique en mode si une scene à une musique à elle ca supprime l'ancienne
	{
		ma_sound_uninit(&m_music);
		m_musicLoad = false;
	}

	if (ma_sound_init_from_file(
		&m_engine,
		_path.c_str(),
		MA_SOUND_FLAG_STREAM,
		nullptr,
		nullptr,
		&m_music)
		!= MA_SUCCESS)
	{
		return;
	}

	ma_sound_set_looping(&m_music, _loop);
	ma_sound_start(&m_music);
	m_musicLoad = true;
}

void AudioSystem::PlaySFX(const std::string& _path)
{
	ma_engine_play_sound(&m_engine, _path.c_str(), nullptr);
}

void AudioSystem::Shutdown()
{
	if (m_musicLoad)
	{
		ma_sound_uninit(&m_music);
	}
	ma_engine_uninit(&m_engine);
}