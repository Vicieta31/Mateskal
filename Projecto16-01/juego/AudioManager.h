#include "sdl.h"
#include "sdl_mixer.h"


#pragma once
class AudioManager
{
public:
	~AudioManager();
	void PlaySound();
	void PlaySound(int channel);
	void StopSound();
	void PlaySoundOnce();

	static AudioManager* getInstance() {

		if (pInstance == NULL) {
			pInstance = new AudioManager();
		}

		return pInstance;

	};

protected:
	AudioManager();

private:
	static AudioManager* pInstance;
};

