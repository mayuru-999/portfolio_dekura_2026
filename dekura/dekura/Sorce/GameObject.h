#pragma once
#include <Siv3D.hpp>

class GameObject
{
public:
	virtual ~GameObject() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	void destroy() {};
};
