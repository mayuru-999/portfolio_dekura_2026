#pragma once
#include "../Library/GameObject.h"

class Notes:public GameObject
{
public:
	Notes();
	Notes(int x, int y, int num);
	~Notes();
	void Update() override;
	void Draw() override;

	bool isHit(VECTOR2 player);

private:
	int nImage;
	float tolerance;
	VECTOR2 position;
};