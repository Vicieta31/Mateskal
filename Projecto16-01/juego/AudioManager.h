#include "sdl.h"
#include "sdl_mixer.h"


#pragma once
class AudioManager
{
public:
	~AudioManager();

protected:
	AudioManager();

private:
	static AudioManager* pInstance;
};

