#pragma once
#include "../Library/GameObject.h"

class pre_game:public GameObject
{
public:
	pre_game();
	pre_game(int level);
	~pre_game();
	void Update() override;
	void Draw() override;

private:
	int count;
};