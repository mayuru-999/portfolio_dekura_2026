#pragma once
#include <Siv3D.hpp>
#include "GameObject.h"

class GameObject;

namespace ObjectManager
{
	void Init();
	void Update();
	void Draw();

	/// @brief GameObjectを追加する。
	void Push(GameObject* obj);

	/// @brief GameObjectを削除する。
	void Pop(GameObject* obj);

	/// @brief drawOrderに基づいて、描画順をソートする。
	void SortByDrawOrder();

	/// @brief 現在のGameObjectを全て探す。
	const std::list<GameObject*>& GetAllObject();
}
