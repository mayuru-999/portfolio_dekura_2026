#include "TitleScene.h"
#include "CheckKey.h" 
#include "Screen.h"
#include "Common.h"

using namespace std;

TitleScene::TitleScene()
{
	titleImage = LoadGraph("data/image/Title.jpg");
	titleState = Title;

	titleUi = new TitleUi();
}

TitleScene::~TitleScene()
{
	DeleteGraph(titleImage);
}

void TitleScene::Update()
{
	UpdateKeyInput();
	if (CheckHitKey(KEY_INPUT_F1)){
		if (KeyPressed(KEY_INPUT_F1)) g.debugMode = !g.debugMode;
	}
	if (CheckHitKey(KEY_INPUT_F10)){
		if (KeyPressed(KEY_INPUT_F10)) SceneManager::ChangeScene("PLAY");;
	}
	if (CheckHitKey(KEY_INPUT_SPACE)){
		if (KeyPressed(KEY_INPUT_SPACE)) StateChange();
	}
	if (CheckHitKey(KEY_INPUT_BACK)){
		if (KeyPressed(KEY_INPUT_BACK)) StateChange(Title);
	}
	if (CheckHitKey(KEY_INPUT_ESCAPE)) {
		SceneManager::Exit();
	}

	switch (titleState)
	{
	case Title:
		if (alpha <= 255) alpha += 10;
		if (titleUi->alpha >= 0) titleUi->alpha -= 10;
		break;

	case SelectMusic:
		if (alpha >= 0) alpha -= 10;
		if (titleUi->alpha <= 255) titleUi->alpha += 10;
		break;

	default:
		break;
	}

}


void TitleScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	//DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(0, 0, 0), TRUE);
	DrawGraph(0, 0, titleImage, FALSE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (!g.debugMode) return;
	DrawFormatString(0, 0, GetColor(0, 0, 0), "TITLE SCENE");
	DrawFormatString(0, 20, GetColor(0, 0, 0), "%d", titleState);
}

void TitleScene::StateChange(int newState)
{
	if (newState != -1) {
		titleState = newState;
		return;
	}

	switch (titleState)
	{
	case Title:
		titleState = SelectMusic;
		break;

	case SelectMusic:
		titleState = Transitioning;
		break;

	//case Transitioning:
	//	SceneManager::ChangeScene("PLAY");
	//	break;

	default:
		break;
	}
}
