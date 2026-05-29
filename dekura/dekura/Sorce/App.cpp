#include "App.h"
#include "ObjectManager.h"

void AppInit()
{
	ObjectManager::Init();
}

void AppUpdate()
{
	ObjectManager::Update();
}

void AppDraw()
{
	ObjectManager::Draw();
}
