#pragma once
#include "Common.h"
#include "../Library/GameObject.h"

class Notes:public GameObject
{
public:
	Notes();
	Notes(int frame, int lane);
	~Notes();
	void Update() override;
	void Draw() override;

	Common::HitType isHit(int currentFrame);

private:
	int frame;
	int lane;

	int nImage;
	int music;
	float speed;
	VECTOR2 position;
};