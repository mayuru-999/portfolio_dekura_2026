#pragma once
#include "Common.h"
#include "../Library/GameObject.h"

class JudgeEffect :public GameObject
{
public:
	JudgeEffect();
	JudgeEffect(Common::HitType hitType);
	~JudgeEffect();

	void Update() override;
	void Draw() override;

private:
	int hImage;
	int hImageWIDTH, hImageHEIGHT;
	VECTOR2 anchor;

	int count = 0;
	float alpha = 255.0f;
	float lifeTime = 0.5f;
	VECTOR2 position;
};
