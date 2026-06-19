#include "Notes.h"
#include "Screen.h"

Notes::Notes()
{
}

Notes::Notes(int x, int y, int num)
{
	position = VECTOR2(x, y);

	char bgfile[60];
	sprintf_s<60>(bgfile, "data/image/skin/notes_%d.png", num);
	nImage = LoadGraph(bgfile);

	tolerance = 5.0f;
}

Notes::~Notes()
{
}

void Notes::Update()
{
	position.y += 1.5;

	if (position.y > Screen::HEIGHT) {
		DestroyMe();
	}
}

void Notes::Draw()
{
	DrawGraph(position.x, position.y, nImage, FALSE);
}

enum JudgeScore Notes::isHit(VECTOR2 player)
{
	if (position.x != player.x) return JudgeScore::NOHIT;
	if (position.y == player.y)
	{
		DestroyMe();
		return JudgeScore::EXCELENT;
	}
	else if (fabsf(position.y - player.y) < tolerance)
	{
		DestroyMe();
		return JudgeScore::GOOD;
	}
	else if (fabsf(position.y - player.y) < tolerance + 10.0f);
	{
		DestroyMe();
		return JudgeScore::MISS;
	}
	return JudgeScore::NOHIT;
}
