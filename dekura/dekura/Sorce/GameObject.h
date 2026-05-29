#pragma once
#include <Siv3D.hpp>

class GameObject
{
private:
	bool destroy;
	bool dontDestroy;
	int drawOrder;
public:
	GameObject() : destroy(false), dontDestroy(false), drawOrder(0) { ObjectManager::Push(this); }
	virtual ~GameObject() { ObjectManager::Pop(this); }

	virtual ~GameObject() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void Destroy() { destroy = true; }
	void DontDestroy() { dontDestroy = true; }

};
