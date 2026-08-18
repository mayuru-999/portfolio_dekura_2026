#pragma once
#include "Common.h"
#include "JudgeEffect.h"
class Score
{
private:
	Common c;

public:
	int score = 0;
	int combo = 0;

	void Init()
	{
		score = 0;
		combo = 0;
	}
	void AddScore(Common::HitType hitType)
	{
		if (hitType == c.NoHit) return;

		new JudgeEffect(hitType);

		if (hitType == c.Miss) {
			combo = 0;
			return;
		}

		new JudgeEffect(hitType);
		score += Common::HitScore[hitType];
		combo++;
	}
};

inline Score s;