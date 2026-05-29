#include "stdafx.h"
#include "ObjectManager.h"

namespace
{
	std::list<GameObject*>* objects;
};

void ObjectManager::Init()
{
	objects = new std::list<GameObject*>;
	objects->clear();
}

void ObjectManager::Update()
{
}

void ObjectManager::Draw()
{
}

void ObjectManager::Push(GameObject* obj)
{
}

void ObjectManager::Pop(GameObject* obj)
{
}

void ObjectManager::SortByDrawOrder()
{
}

const std::list<GameObject*>& ObjectManager::GetAllObject()
{
	return *objects;
}
