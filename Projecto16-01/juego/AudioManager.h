#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include <map>
#include <vector>
#include <string>
#include <SDL_mixer.h>
#include <SDL.h>
#include <iostream>


//! AudioManager class
/*!
	Handles the load and management of the sounds in the game.
*/
class AudioManager
{
public:

	//! Destructor.
	~AudioManager();

	//! Deletes a sound from the AudioManager map
	/*!
		\param file Filepath to the sound
	*/
	void removeSound(const char* file);


	//! Gets the sound ID from file name. Uses addSound if it needs to load sound from disc
	/*!
		\param file Filepath to the sound
		\return ID of the sound
	*/
	Sint32 loadAndGetSoundID(const char* file);


	//! Gets the sound path given an ID to a sound
	/*!
		\param ID of the sound
		\return Filepath to the sound
	*/
	std::string getSoundPathByID(Sint32 ID);

	//! Returns the Mix_Chunk of the Sound. Only for playing.
	/*!
		\param ID ID of the sound
		\return Mix_Chunk
	*/
	Mix_Chunk* getSoundByID(Sint32 ID);

	//! Gets Singleton instance
	/*!
		\return Instance of AudioManager (Singleton).
	*/
	static AudioManager* getInstance() {
	
		if (pInstance == NULL) {
			pInstance = new AudioManager;
		}

		return pInstance;
	
	};

protected:
	//! Constructor of an empty AudioManager.
	AudioManager();

private:

	//! Loads from disc and adds a sound to the AudioManager 
	/*!
		\param file Filepath to the graphic
		\return -1 if there's an error when loading, or the ID where the sound is added/stored if it was already loaded.
	*/
	Sint32 addSound(const char* file);

	//! Searches the first NULL in mSoundsVector and updates mFirstFreeSlot to store its position
	/*!
		\return Index of the first NULL in mSoundsVector
	*/
	Uint32 updateFirstFreeSlotSound();

	std::vector<Mix_Chunk*>	mSoundsVector;	/*!<  Vector that stores Chunks.*/
	std::map<std::string, Sint32>	mIDMap;			/*!<  Map that stores ID. Links strings to ID, Useful for checking if a sound is has been loaded previously*/
	Uint32				mFirstFreeSlot;		/*!<  First free slot in the mSoundsVector*/
	static AudioManager* pInstance;		/*!<  Singleton instance*/
};

#endif