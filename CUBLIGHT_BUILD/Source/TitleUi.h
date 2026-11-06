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
	bool canStart = false;
private:
	int headerGraph;
	int selectedIndex = 0;

	int fontTitle;
	int fontLabel;
	int fontSmall;

	UiImage* m_header;
	UiImage* m_thumbnail;
	UiLabel* m_titleLabel[1025];
	UiBox* m_levelBoxes[3];
	UiBox* m_startButton;

	SongLoader loader;
	//Common::SongData& selectedSong;

	bool isSelected = false;
	bool cantPlaySong[255];
};