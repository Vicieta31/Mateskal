#pragma once
#include <string>
#include "SDL.h"

class SoundManager
{
public:
	~SoundManager();

	/*! Plays the specified sound.
		\param file Filepath to the sound
		\param loop Loops the sound infinitely if true
	*/
	void PlaySound(std::string file, bool loop);

	/*! Stops the specified sound.
		\param file Filepath to the sound
	*/
	void StopSound(std::string file);

	// Stops all sounds currently playing
	void MuteSound();

	// Pauses all sounds currently playing
	void PauseSound();

	// Resumes all sounds currently playing
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

