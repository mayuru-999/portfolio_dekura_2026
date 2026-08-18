#include "BootScene.h"
#include "DebugCursol.h"

BootScene::BootScene()
{
	new DebugCursol();
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
