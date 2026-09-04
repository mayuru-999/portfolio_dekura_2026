#include "PlayScene.h"
#include "Loader.h"
#include "CheckKey.h"
#include "Score.h"
#include "Sound.h"

PlayScene::PlayScene()
{
	new Loader();
	new Sound();
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
	UpdateKeyInput();

	if (CheckHitKey(KEY_INPUT_F1))
	{
		if (KeyPressed(KEY_INPUT_F1)) g.debugMode = !g.debugMode;
	}
	if (CheckHitKey(KEY_INPUT_F2))
	{
		if (KeyPressed(KEY_INPUT_F2)) g.autoPlay = !g.autoPlay;
	}
	if (CheckHitKey(KEY_INPUT_T)) {
		SceneManager::ChangeScene("TITLE");
		s.Init();
	}
}

void PlayScene::Draw()
{
	DrawFormatString(0, 100, GetColor(0, 0, 0), "SCORE: %d", s.score);
	DrawFormatString(0, 120, GetColor(0, 0, 0), "COMBO: %d", s.combo);

	if (!g.debugMode) return;

	DrawString(0, 0, "PLAY SCENE", GetColor(0, 0, 0));
	DrawFormatString(0, 20, GetColor(0, 0, 0), "FPS: %.1lf", GetFPS());

	//for (int i = 0;i < Screen::WIDTH;i += 10)
	//{
	//	DrawLine(i, 0, i, Screen::HEIGHT, GetColor(255, 255, 255), 1);
	//}
	//for (int i = 0;i < Screen::HEIGHT;i += 10)
	//{
	//	DrawLine(0, i, Screen::WIDTH, i, GetColor(255, 255, 255), 1);
	//}
	
}
