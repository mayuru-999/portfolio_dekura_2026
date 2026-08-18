#pragma once
#include <DxLib.h>
#include "TitleUi.h"
#include "../Library/SceneBase.h"

/// <summary>
/// タイトルシーン
/// 
/// タイトルを表示して、キーを押したらプレイシーンに移行する。
/// </summary>
class TitleScene : public SceneBase
{
private:
	int titleImage;
	int titleState;
	int alpha = 255;
	TitleUi* titleUi;

	enum State
	{
		Title,
		SelectMusic,
		Transitioning
	};
public:
	TitleScene();
	~TitleScene();
	void Update() override;
	void Draw() override;
	void StateChange(int newState = -1);
};
