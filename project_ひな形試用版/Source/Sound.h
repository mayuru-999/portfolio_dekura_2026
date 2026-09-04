#pragma once
#include "../Library/GameObject.h"

class Sound :public GameObject
{
public:
	Sound();
	void playSound(const char* name);
	~Sound();

private:
	int se;
};
