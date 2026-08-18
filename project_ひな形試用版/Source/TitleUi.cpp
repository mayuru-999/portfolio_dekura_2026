#include "TitleUi.h"
#include "Screen.h"
#include "CheckKey.h" 

TitleUi::TitleUi()
{
	loader.Load();

	//m_titleLabel = new UiLabel(80, 70, "", 1, GetColor(0, 0, 0));
	m_thumbnail = new UiImage(800, 120, 360, 360, loader.songs[0].songImage);
	m_levelButtons[0] = new UiButton();
	m_levelButtons[1] = new UiButton();
	m_levelButtons[2] = new UiButton();
	m_startButton = new UiButton();
}

TitleUi::~TitleUi()
{
}

void TitleUi::Update()
{
	if (CheckHitKey(KEY_INPUT_UP)) {
		if (KeyPressed(KEY_INPUT_UP)) 
		{
			selectedIndex--;
			selectedIndex = max(selectedIndex, 0);
			UpdateUi();
		}
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) {
		if (KeyPressed(KEY_INPUT_DOWN))
		{
			selectedIndex++;
			selectedIndex = min(selectedIndex, loader.songCount - 1);
			UpdateUi();
		}
	}
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		if (KeyPressed(KEY_INPUT_RETURN))
		{
			SceneManager::selectedMusic = loader.songs[selectedIndex];
			printfDx(
				"music = %s \n",
				loader.songs[selectedIndex].bgmPath.c_str()
			);
			SceneManager::ChangeScene("PLAY");
		}
	}
}

void TitleUi::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha);
	DrawBox(0, 0, Screen::WIDTH, Screen::HEIGHT, GetColor(255, 255, 255), TRUE);

	for (int i = 0; i < loader.songCount; i++) 
	{
		int color = (i == selectedIndex) ? GetColor(255, 0, 0) : GetColor(0, 0, 0);
		DrawString(100, 100 + i * 30, loader.songs[i].name.c_str(), color);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleUi::UpdateUi()
{
	m_thumbnail->SetImage(loader.songs[selectedIndex].songImage);
}
