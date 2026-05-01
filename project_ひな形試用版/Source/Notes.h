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

private:
	int nImage;
	VECTOR2 position;
};