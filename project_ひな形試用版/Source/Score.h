#pragma once
#include "../Library/GameObject.h"

class Score :public GameObject
{
public:
	Score();
	~Score();

private:
	int totalScore;
	int ExCount;
};