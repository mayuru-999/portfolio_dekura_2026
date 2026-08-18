#pragma once
#include "Common.h"
#include "SongLoader.h"
#include "UiElements.h"
#include "../Library/GameObject.h"

using namespace std;
class TitleUi :public GameObject
{
public:
	TitleUi();
	~TitleUi();
	void Update() override;
	void Draw() override;
	void UpdateUi();

	int alpha = 0;
private:
	int titleImage;
	int backgroundImage;
	int selectedIndex = 0;

	UiLabel* m_titleLabel;
	UiImage* m_thumbnail;
	UiButton* m_levelButtons[3];
	UiButton* m_startButton;

	SongLoader loader;
	//Common::SongData& selectedSong;
};