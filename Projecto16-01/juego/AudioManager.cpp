#include "AudioManager.h"
#include "SDL_mixer.h"


AudioManager* AudioManager::pInstance = NULL;

AudioManager::AudioManager()
{
	mFirstFreeSlot = 0;
}

AudioManager::~AudioManager()
{
}

Sint32 AudioManager::addSound(const char* file)
{
	Sint32 Return = -1;

	Mix_Chunk* Sound1 = NULL;

	Sound1 = Mix_LoadWAV(file);

	if (Sound1 != NULL) {

		if (mFirstFreeSlot == mSoundsVector.size()) {

			mSoundsVector.push_back(Sound1);

			Return = mSoundsVector.size() - 1;

			mFirstFreeSlot = mSoundsVector.size();

			mIDMap.insert(std::pair<std::string, Sint32>(file, Return));

		}
		else {

			mSoundsVector[mFirstFreeSlot] = Sound1;

			Return = mFirstFreeSlot;

			mIDMap.insert(std::pair<std::string, Sint32>(file, Return));

			AudioManager::getInstance()->updateFirstFreeSlotSound();

		}

	}

	return Return;
}

void AudioManager::removeSound(const char* file)
{
	std::map<std::string, Sint32>::iterator Iterator;

	Iterator = mIDMap.find(file);

	if (Iterator != mIDMap.end()) {

		int id = Iterator->second;

		mIDMap.erase(Iterator);

		Mix_FreeChunk(mSoundsVector[id]);

		mSoundsVector[id] = NULL;

		mFirstFreeSlot = updateFirstFreeSlotSound();

	}
}

Uint32 AudioManager::updateFirstFreeSlotSound()
{
	for (int i = 0; i < mSoundsVector.size(); i++) {

		if (mSoundsVector[i] == NULL) {

			return i;

		}

	}

	return mSoundsVector.size();
}

Sint32 AudioManager::loadAndGetSoundID(const char* file)
{
	std::map<std::string, Sint32>::iterator Iterator;

	Iterator = mIDMap.find(file);

	Sint32 Return = -1;

	if (Iterator == mIDMap.end()) {

		Return = addSound(file);

	}
	else {

		Return = Iterator->second;

	}
	
	return Return;
}

std::string AudioManager::getSoundPathByID(Sint32 ID)
{
	std::map<std::string, Sint32>::iterator Iterator;

	std::string Return = "NULL";

	if ((ID > mSoundsVector.size()) || (ID < 0)) {

		Return = "NULL";

	}
	else {

		for (Iterator = mIDMap.begin(); Iterator != mIDMap.end(); ++Iterator) {

			if (Iterator->second == ID) {

				Return = Iterator->first;
			}
		}
	}

	return Return;
}

Mix_Chunk* AudioManager::getSoundByID(Sint32 ID)
{
	Mix_Chunk* Return = NULL;

	Return = mSoundsVector[ID];

	return Return;
}


