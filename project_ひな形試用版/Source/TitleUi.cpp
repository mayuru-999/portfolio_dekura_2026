#include "TitleUi.h"
#include "Screen.h"
#include "CheckKey.h" 

TitleUi::TitleUi()
{
	loader.Load();

	headerGraph = LoadGraph("data/image/Header.png");

	fontTitle = CreateFontToHandle(UiFonts::Archivo.c_str(), 24, -1);
	fontLabel = CreateFontToHandle(UiFonts::Inter.c_str(), 18, -1);
	fontSmall = CreateFontToHandle(UiFonts::Inter.c_str(), 12, -1);

	for (int i = 0; i < loader.songCount; i++) 
		m_titleLabel[i] = new UiLabel(100, 100 + i * 50, loader.songs[i].name.c_str(), fontTitle, GetColor(0, 0, 0));

	m_header	 = new UiImage(540, 23, 181, 45, headerGraph);
	m_thumbnail  = new UiImage(800, 120, 360, 360, loader.songs[0].songImage, GetColor(0, 0, 0),3);
	m_levelBoxes[0] = new UiBox(800, 500, 113, 56, GetColor(0, 0, 0), "EASY", fontLabel);
	m_levelBoxes[1] = new UiBox(923, 500, 113, 56, GetColor(0, 0, 0), "NORMAL", fontLabel);
	m_levelBoxes[2] = new UiBox(1046, 500, 113, 56, GetColor(0, 0, 0), "HARD", fontLabel);
	m_startButton = new UiBox(800,572,1120,33, GetColor(0, 0, 0), "PLAY START", fontLabel);
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

	/*for (int i = 0; i < loader.songCount; i++) 
	{
		int color = (i == selectedIndex) ? GetColor(255, 0, 0) : GetColor(0, 0, 0);
		DrawString(100, 100 + i * 30, loader.songs[i].name.c_str(), color);
	}*/
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void TitleUi::UpdateUi()
{
	m_thumbnail->SetImage(loader.songs[selectedIndex].songImage);
	for (int i = 0; i < loader.songCount; i++)
	{
		int color = (i == selectedIndex) ? GetColor(255, 0, 0) : GetColor(0, 0, 0);
		m_titleLabel[selectedIndex]->SetTextColor(color);
	}
	printfDx(
		"selectedIndex=%d",
		selectedIndex
	);
}
