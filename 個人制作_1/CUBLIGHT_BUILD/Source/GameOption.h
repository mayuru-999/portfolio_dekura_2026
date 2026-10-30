#pragma once
class GameOption
{
public:
	float noteSpeed = 9.0f;
	float playerSpeed = 10.0f;
	float soundVolume = 100.0f;
	float musicVolume = 100.0f;

	int judgeEffectPositionY = 100;

	bool debugMode = false;
	bool autoPlay = false;
};

inline GameOption g;
