#include "JudgeEffect.h"
#include "Screen.h"
#include "GameOption.h"

JudgeEffect::JudgeEffect()
{
}

JudgeEffect::JudgeEffect(Common::HitType hitType)
{
	Common c;
	hImage = DerivationGraph(0, 160 * hitType, 640, 160, LoadGraph("data/image/effect/JudgeEffect.png"));
	GetGraphSize(hImage, &hImageWIDTH, &hImageHEIGHT);
	anchor = VECTOR2(hImageWIDTH / 2, hImageHEIGHT / 2);
	position = VECTOR2(Screen::WIDTH / 2 - anchor.x, g.judgeEffectPositionY - anchor.y);
}

JudgeEffect::~JudgeEffect()
{
	DeleteGraph(hImage);
}

void JudgeEffect::Update()
{
	count++;
	if(count > lifeTime * Screen::FRAME_RATE)
	{
		position.y += 1.0f;
		alpha -= 20.0f;
		if (alpha <= 0) DestroyMe();
	}
}

void JudgeEffect::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawGraph(position.x, position.y, hImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	//DrawExtendGraph(position.x, position.y, position.x + 256, position.y + 64, hImage, TRUE);
}
