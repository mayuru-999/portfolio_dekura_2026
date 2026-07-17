#include "Player.h"
#include "Notes.h"
#include <algorithm>

using namespace std;

Player::Player()
{
	jgLImage = LoadGraph("data/image/skin/JGline_L.png");
	jgRImage = LoadGraph("data/image/skin/JGline_R.png");
	jgacImage = LoadGraph("data/image/skin/JGline_active.png");

	playerSpeed = 5;
	movement = 0;
	player = VECTOR2(561, 0);
}

Player::~Player()
{
}

void Player::Update()
{
	fill(&activeKey[0],&activeKey[3], FALSE);

	if (CheckHitKey(KEY_INPUT_J))
	{
		activeKey[0] = TRUE;
		CheckHitNotes(0);
	}
	else wasActive[0] = FALSE;

	if (CheckHitKey(KEY_INPUT_K))
	{
		activeKey[1] = TRUE;
		CheckHitNotes(1);
	}
	else wasActive[1] = FALSE;

	if (CheckHitKey(KEY_INPUT_L))
	{
		activeKey[2] = TRUE;
		CheckHitNotes(2);
	}
	else wasActive[2] = FALSE;

	PlayerMove();

	

	for (int i = 0; i < 3; i++)
	{
		if(activeKey[i])
		{
			wasActive[i] = TRUE;
		}
	}
}

void Player::Draw()
{
	//DrawBox(0, 0, player.x, 720, GetColor(0, 0, 0), TRUE);
	DrawBox(player.x, 0, player.x + 74 * 3, 720, GetColor(255, 255, 255), TRUE);
	for (int i = 0; i < 12; i++) {
		DrawGraph(196 + (74 * i), 600, jgLImage, TRUE);
		DrawLine(191 + (74 * i), 0, 191 + (74 * i), 720, GetColor(155, 155, 155), 2);
	}
	for (int i = 0; i < 3; i++) {
		DrawGraph(player.x + 5 + (74 * i), 600, jgRImage, TRUE);
	}
	DrawLine(191 + (74 * 12), 0, 191 + (74 * 12), 720, GetColor(155, 155, 155), 2);
	for (int i = 0; i < 3; i++)
	{
		if (activeKey[i]) {
			DrawGraph(player.x + 5 + (74 * i), 600, jgacImage, TRUE);
		}
	}
}

void Player::PlayerMove()
{
	//移動モード
	if (move2L) {
		//判定バー移動速度(▶変数化する)
		player.x -= playerSpeed;
		movement -= playerSpeed;
		//移動量が1ライン分になったら
		if (movement <= -74) {
			//1ラインでぴったり止め、
			player.x += -74 - movement;
			movement = 0;
			//移動モードを解除する
			move2L = FALSE;
		}
	}
	else if (move2R)
	{
		player.x += playerSpeed;
		movement += playerSpeed;
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
		if ((CheckHitKey(KEY_INPUT_LEFT) || CheckHitKey(KEY_INPUT_A)) && player.x > 191) {
			move2L = TRUE;
		}
		if ((CheckHitKey(KEY_INPUT_RIGHT) || CheckHitKey(KEY_INPUT_D)) && player.x < 857) {
			move2R = TRUE;
		}
	}
}

void Player::CheckHitNotes(int num)
{
	VECTOR2 jg = VECTOR2(player.x + 5 + (74 * num), 600);
	auto notes = FindGameObjects<Notes>();
	for (auto n : notes) 
	{
	}
}
