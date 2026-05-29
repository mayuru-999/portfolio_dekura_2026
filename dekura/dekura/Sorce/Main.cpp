#include <Siv3D.hpp> // Siv3D v0.6.16
#include "App.h"

void Main()
{
	AppInit();

	while (System::Update())
	{
		AppUpdate();
		AppDraw();
	}
}
