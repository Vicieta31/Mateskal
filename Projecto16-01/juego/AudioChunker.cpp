#include "AudioChunker.h"
#include "AudioManager.h"

void AudioChunker() {

	/*
		To add an audio file to the project, simply execute this command:

		AudioManager::getInstance()->loadAndGetSoundID(PATH);

		With PATH replaced by the file's path in quotes("") in this function, then call this function in the main.

	*/

	//Total Count of audio files: 8

	//Placeholder Audio Files: 8

	AudioManager::getInstance()->loadAndGetSoundID("Sounds/death.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/gameover.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/Monster-Snoring.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/shock-wall.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/step-human.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/step-monster.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/victory.wav");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/waterfall.wav");

	AudioManager::getInstance()->loadAndGetSoundID("Sounds/end.mp3");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/backMu.mp3");
	AudioManager::getInstance()->loadAndGetSoundID("Sounds/shot.mp3");

	//Final Version Audio Files: 0

}