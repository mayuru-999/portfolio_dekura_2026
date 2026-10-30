#include "Sound.h"

Sound::Sound()
{
	se = LoadSoundMem("data/hit.mp3");
}

void Sound::playSound(const char* name)
{
	ChangeNextPlayVolumeSoundMem(80, se);

	if (name == "HIT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "MISS")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "EXCELLENT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "GOOD")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "HIT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "MISS")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "EXCELLENT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "GOOD")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "HIT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "MISS")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "EXCELLENT")PlaySoundMem(se, DX_PLAYTYPE_BACK);
	else if (name == "GOOD")PlaySoundMem(se, DX_PLAYTYPE_BACK);
}

Sound::~Sound()
{
}
