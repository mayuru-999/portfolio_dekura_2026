#include <Siv3D.hpp> // Siv3D v0.6.16
#include "GameObject.h"

void Main()
{
	Array<std::shared_ptr<GameObject>> objects;

	while (System::Update())
	{
		for (auto& obj : objects)
		{
			obj->Update();
		}
		for (auto& obj : objects)
		{
			obj->Draw();
		}
	}
}
