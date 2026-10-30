#include "BootScene.h"
#include "DebugCursol.h"

BootScene::BootScene()
{
	new DebugCursol();
	AddFontFile("data/font/ArchivoBlack-Regular.ttf");
	AddFontFile("data/font/Inter-VariableFont_opsz,wght.ttf");
}

BootScene::~BootScene()
{
}

void BootScene::Update()
{
	SceneManager::ChangeScene("TITLE"); // ‹N“®‚ªI‚í‚Á‚½‚çTitle‚ğ•\¦
}

void BootScene::Draw()
{
}
