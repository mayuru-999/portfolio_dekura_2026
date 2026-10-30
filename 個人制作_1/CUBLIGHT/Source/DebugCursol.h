#pragma once
#include "../Library/GameObject.h"
class DebugCursol :public GameObject
{
public:
	DebugCursol();
	~DebugCursol();
	void Update() override;
	void Draw() override;

private:
	int x, y;
};
