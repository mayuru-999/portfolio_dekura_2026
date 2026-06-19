#pragma once
#include "../Library/GameObject.h"

enum class JudgeScore
{
	EXCELENT,
	GOOD,
	HIT,
	MISS,
	NOHIT
};

class Notes:public GameObject
{
public:
	Notes();
	Notes(int x, int y, int num);
	~Notes();
	void Update() override;
	void Draw() override;

	enum JudgeScore isHit(VECTOR2 player);

private:
	int nImage;
	float tolerance;
	VECTOR2 position;
};