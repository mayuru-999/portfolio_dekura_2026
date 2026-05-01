#include "Player.h"
#include <algorithm>

using namespace std;

Player::Player()
{
	jgLImage = LoadGraph("data/image/skin/JGline_L.png");
	jgRImage = LoadGraph("data/image/skin/JGline_R.png");
	jgacImage = LoadGraph("data/image/skin/JGline_active.png");

	movement = 0;
	player = VECTOR2(640, 0);
}

Player::~Player()
{
}

void Player::Update()
{
	fill(&activeKey[0],&activeKey[6], FALSE);

	if (CheckHitKey(KEY_INPUT_S)) {
		activeKey[0] = TRUE;
	}
	if (CheckHitKey(KEY_INPUT_D)) {
		activeKey[1] = TRUE;
	}
	if (CheckHitKey(KEY_INPUT_F)) {
		activeKey[2] = TRUE;
	}

	if (CheckHitKey(KEY_INPUT_J)) {
		activeKey[3] = TRUE;
	}
	if (CheckHitKey(KEY_INPUT_K)) {
		activeKey[4] = TRUE;
	}
	if (CheckHitKey(KEY_INPUT_L)) {
		activeKey[5] = TRUE;
	}

	//移動モード
	if (move2L) {
		//判定バー移動速度(▶変数化する)
		player.x -= 2;
		movement -= 2;
		//移動量が1ライン分になったら
		if (movement <= -74) {
			//1ラインでぴったり止め、
			player.x += -74 - movement;
			movement = 0;
			//移動モードを解除する
			move2L = FALSE;
		}
	}
	else if(move2R)
	{
		player.x += 2;
		movement += 2;
		if (movement >= 74) {
			player.x += 74 - movement;
			movement = 0;
			move2R = FALSE;
		}
	}
	//非移動モード
	else
	{
		//入力によって移動モードに移行
		if ((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) && player.x > 418) {
			move2L = TRUE;
		}
		if ((CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_SEMICOLON)) && player.x < 862) {
			move2R = TRUE;
		}
	}
}

void Player::Draw()
{
	//DrawBox(0, 0, player.x, 720, GetColor(0, 0, 0), TRUE);
	DrawBox(player.x, 0, player.x + 74 * 3, 720, GetColor(255, 255, 255), TRUE);

	//DrawLine(player.x, 0, player.x, 720, GetColor(255, 255, 0),3);

	for (int i = 0;i < 6;i++) {
		if (activeKey[i])
		{
			DrawGraph(423 + (74 * i), 600, jgacImage, TRUE);
		}
		else
		{
			DrawGraph(423 + (74 * i), 600, jgLImage, TRUE);
		}
		DrawLine(418 + (74 * i), 0, 418 + (74 * i), 720, GetColor(155, 155, 155), 2);
	}
	DrawLine(862, 0, 862, 720, GetColor(155, 155, 155), 2);
	
}
