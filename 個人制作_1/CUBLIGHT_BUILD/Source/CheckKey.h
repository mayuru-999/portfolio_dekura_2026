#pragma once
#include <DxLib.h>

inline int keyCountArray[256] = {};

inline void UpdateKeyInput()
{
	char key[256];
	GetHitKeyStateAll(key);

	for (int i = 0; i < 256; i++)
	{
		keyCountArray[i] = (key[i] != 0) ? keyCountArray[i] + 1 : 0;
	}
}

inline bool KeyPressed(int keyCode)
{
	return keyCountArray[keyCode] == 1;
}
