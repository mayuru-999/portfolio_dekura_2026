#pragma once
#include "Common.h"
#include "JudgeEffect.h"
#include "Sound.h"

class Score
{
public:
	struct JudgeScore
	{
		int excellent = 0;
		int good = 0;
		int hit = 0;
		int miss = 0;
	};

private:
	Common c;
	Sound* s;
	JudgeScore jgScore{ 0,0,0,0 };

public:
	int score = 0;
	int combo = 0;
	int maxCombo = 0;

	void Init()
	{
		score = 0;
		combo = 0;
		maxCombo = 0;
		jgScore = { 0,0,0,0 };
	}
	void AddScore(Common::HitType hitType)
	{
		s = FindGameObject<Sound>();

		if (hitType == c.NoHit) return;

		new JudgeEffect(hitType);

		jgScore.excellent += (hitType == c.Excellent) ? 1 : 0;
		jgScore.good += (hitType == c.Good) ? 1 : 0;
		jgScore.hit += (hitType == c.Hit) ? 1 : 0;
		jgScore.miss += (hitType == c.Miss) ? 1 : 0;

		if (hitType == c.Miss) {
			combo = 0;
			return;
		}
		else s->playSound("HIT");

		score += Common::HitScore[hitType];
		combo++;
		maxCombo = max(maxCombo, combo);
	}

	JudgeScore getResult() { return jgScore; }
};

inline Score s;