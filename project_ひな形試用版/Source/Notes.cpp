#include "Notes.h"
#include "Screen.h"
#include "Common.h"
#include "GameOption.h"

Notes::Notes()
{
}

Notes::Notes(int m_frame, int m_lane)
{
	GameOption g;
	speed = g.noteSpeed;

	frame = m_frame;
	lane = m_lane;
	position = VECTOR2(196 + (lane * 74), 0);
	position.y = (float)(561 - frame * speed);

	char bgfile[60];
	sprintf_s<60>(bgfile, "data/image/skin/notes_%d.png", 1);
	nImage = LoadGraph(bgfile);

	music = LoadSoundMem("data/hit.mp3");
}

Notes::~Notes()
{
}

void Notes::Update()
{
	position.y += speed;
	if (position.y == 561) {
		PlaySoundMem(music, 255);
	}
	if (position.y > Screen::HEIGHT) {
		DestroyMe();
	}
}

void Notes::Draw()
{
	DrawGraph(position.x, position.y, nImage, FALSE);
}

Common::HitType Notes::isHit(int currentFrame)
{
	Common c;
	int diff = currentFrame - frame;

	if (diff < 0)	return c.Miss;
	else if (diff <= c.HitThreshold[c.Excellent]) {
		DestroyMe();
		return c.Excellent;
	}
	else if (diff <= c.HitThreshold[c.Good]) {
		DestroyMe();
		return c.Good;
	}
	else if (diff <= c.HitThreshold[c.Hit]) {
		DestroyMe();
		return c.Hit;
	}
	else if (diff <= c.HitThreshold[c.Miss]) {
		DestroyMe();
		return c.Miss;
	}
}

