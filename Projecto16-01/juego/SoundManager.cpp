#include "SoundManager.h"
#include "AudioManager.h"

SoundManager* SoundManager::pInstance = NULL;

SoundManager::SoundManager()
{
	SDL_Init(SDL_INIT_AUDIO);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

	Mix_AllocateChannels(128);

}

SoundManager::~SoundManager()
{
}

void SoundManager::PlaySound(std::string file, bool loop)
{

	int Loop = 0;

	if (loop) {
		Loop = -1;
	}

	Sint32 ID = AudioManager::getInstance()->loadAndGetSoundID(file.c_str());

	Mix_Chunk * Sound = AudioManager::getInstance()->getSoundByID(ID);

	if (loop) {
		Mix_PlayChannel(0, Sound, Loop);
	}
	else {
		Mix_PlayChannel(-1, Sound, Loop);
	}

}

void SoundManager::StopSound(std::string file)
{

	Sint32 ID = AudioManager::getInstance()->loadAndGetSoundID(file.c_str());

	Mix_HaltChannel(ID);

}

void SoundManager::MuteSound()
{

	Mix_HaltChannel(-1);

}

void SoundManager::PauseSound()
{

	Mix_Pause(-1);

}

void SoundManager::ResumeSound()
{

	Mix_Resume(-1);

}
