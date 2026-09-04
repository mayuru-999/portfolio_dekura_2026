#pragma once
#include <fstream>
#include <sstream>
#include "Common.h"
#include "Screen.h"
#include "GameOption.h"
#include "../Library/GameObject.h"
using namespace std;

class Loader:public GameObject
{
public:
	Loader();
	~Loader();
	void Update() override;

	bool Load(const char* path);
	void ChangeMusicStatus(const char* mode);

	float GetMusicTime() const;

private:
	float   bpm =	120.0f;	//BPM
	int beatNum =	4;		//”q(•ªq)
	int beatDen =	4;		//”q(•ª•ê)

	Common::NoteData notes[1024];
	int noteCount = 0;

	int volume = 100;

	float gameEnd = 0.0;
	bool gameEnded = false;

	int music;
	int startTime;
	float musicTime = 0.0f;
	bool isLoaded = false;
	bool isPlayed = false;
	bool beforeDebugMode = false;
};