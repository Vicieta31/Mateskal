#pragma once
#include <string>
#include "SDL.h"

class SoundManager
{
public:
	~SoundManager();

	void PlaySound(std::string file, bool loop);
	void StopSound(std::string file);
	void MuteSound();
	void PauseSound();
	void ResumeSound();

	static SoundManager* getInstance() {

		if (pInstance == NULL) {
			pInstance = new SoundManager();
		}

		return pInstance;

	};

protected:
	SoundManager();

private:
	static SoundManager* pInstance;
};

