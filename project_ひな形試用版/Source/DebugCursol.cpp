#include "DebugCursol.h"
#include "Screen.h"
#include "GameOption.h"
#include "CheckKey.h"

DebugCursol::DebugCursol()
{
	DontDestroyOnSceneChange();
	SetDrawOrder(-1000000);
}

DebugCursol::~DebugCursol()
{
}

void DebugCursol::Update()
{
	GetMousePoint(&x, &y);
}

void DebugCursol::Draw()
{
	if (!g.debugMode) return;
	DrawLine(x, 0, x, Screen::HEIGHT, GetColor(255, 0, 0), 1);
	DrawLine(0, y, Screen::WIDTH, y, GetColor(255, 0, 0), 1);
	DrawCircle(x, y, 0.5, GetColor(255, 0, 0), TRUE);
	DrawFormatString(x + 5, y - 5, GetColor(255, 0, 0), "X: %d, Y: %d", x, y);
}
