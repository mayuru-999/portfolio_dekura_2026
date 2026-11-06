#pragma once
#include "Common.h"
#include "GameOption.h"
#include "../Library/GameObject.h"

class Notes:public GameObject
{
public:
	Notes();
	Notes(int m_lane, float m_timing);
	~Notes();
	void Update() override;
	void Draw() override;

	Common::HitType isHit(int m_lane);

private:
	int lane;
	float timing;

	int nImage;
	int music;
	VECTOR2 position;
};