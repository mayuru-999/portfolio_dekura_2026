#include "Notes.h"
#include "Screen.h"
#include "Common.h"
#include "Score.h"
#include "Loader.h"
#include "GameOption.h"

Notes::Notes()
{
}

Notes::Notes(int m_lane, float m_timing)
{
	lane = m_lane;
	timing = m_timing;
	position = VECTOR2(196 + (lane * 74), 0);

	char bgfile[60];
	sprintf_s<60>(bgfile, "data/image/skin/note.png");
	nImage = LoadGraph(bgfile);

	music = LoadSoundMem("data/hit.mp3");
}

Notes::~Notes()
{
}

void Notes::Update()
{
	Common c;
	Loader* l = FindGameObject<Loader>();

	float songTime = l->GetMusicTime();
	float frameDiff = (timing - songTime) * Screen::FRAME_RATE; //自身のtimingと曲の再生時間の差(フレーム)
	position.y = c.judgeLine - (frameDiff * g.noteSpeed);		//判定ラインからの差分を計算し、ノーツの位置を更新

	if (frameDiff <= 0.02) {
		//ChangeVolumeSoundMem(g.soundVolume, music);
		//PlaySoundMem(music, DX_PLAYTYPE_BACK);

		if (g.autoPlay) s.AddScore(isHit(lane));
	}
	if (songTime > timing + (c.HitThreshold[c.Miss] * Screen::FRAME_RATE / 1000.0)) {
		DestroyMe();
		s.AddScore(c.Miss);
	}
}

void Notes::Draw()
{
	DrawGraph(position.x, position.y, nImage, FALSE);
}

Common::HitType Notes::isHit(int m_lane)
{
	Common c;
	Loader* l = FindGameObject<Loader>();

	float songTime = l->GetMusicTime();
	int frameDiff = abs(timing - songTime) * Screen::FRAME_RATE; //自身のtimingと曲の再生時間の差(フレーム(絶対値))

	if (m_lane != lane)return c.NoHit;

	if (frameDiff < 0) {
		return c.Miss;
	}
	else if (frameDiff <= c.HitThreshold[c.Excellent]) {
		DestroyMe();
		return c.Excellent;
	}
	else if (frameDiff <= c.HitThreshold[c.Good]) {
		DestroyMe();
		return c.Good;
	}
	else if (frameDiff <= c.HitThreshold[c.Hit]) {
		DestroyMe();
		return c.Hit;
	}
	else if (frameDiff <= c.HitThreshold[c.Miss]) {
		DestroyMe();
		return c.Miss;
	}
	else {
		return c.NoHit;
	}
}

