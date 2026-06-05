#pragma once
#include "../Library/GameObject.h"

class Player:public GameObject
{
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;

	void PlayerMove();
	void CheckHitNotes(int num);

private:
	int jgLImage;	//”»’èƒ‰ƒCƒ“
	int jgRImage;	//”»’èƒ‰ƒCƒ“
	int jgacImage;	//”»’èƒ‰ƒCƒ“

	int playerSpeed;
	int movement;

	bool move2L = FALSE;
	bool move2R = FALSE;
	bool activeKey[3];
	bool wasActive[3];

	VECTOR2 player;
};