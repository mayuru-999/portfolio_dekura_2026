#pragma once
#include <fstream>
#include <sstream>
#include "Common.h"
#include "Screen.h"
#include "../Library/GameObject.h"
using namespace std;

class Loader:public GameObject
{
public:
	Loader();
	~Loader();
	void Update() override;

public:
	float   bpm =	120.0f;	//BPM
	int beatNum =	4;		//拍子(分子)
	int beatDen =	4;		//拍子(分母)

	Common::NoteData notes[1024];
	int noteCount = 0;

	bool Load(const char* path) 
	{
		ifstream file(path);
		if (!file.is_open()) return false;

		string line;
		while (getline(file, line))	//getline(元データ、格納先、区切る文字)
		{
			if (line.empty() || line[0] == '#') continue; //空白行はスキップ
			
			istringstream ss(line); //行にあるやつ全部格納
			string token;
			string tokens[5];
			int count = 0;

			while (getline(ss, token, ',') && count <= 4)
			{
				tokens[count++] = token;
			}

			if (tokens[0] == "BPM") 
			{
				bpm = stof(tokens[1]);
				continue;
			}
			if (tokens[0] == "BEAT") 
			{
				beatNum = stof(tokens[1]);
				beatDen = stof(tokens[2]);
				continue;
			}

			Common::NoteData n;
			n.measure = stoi(tokens[0]);
			n.beat	  = stoi(tokens[1]);
			n.sub	  = stoi(tokens[2]);
			n.lane = stoi(tokens[3]) - 1;

			float secBeat = Screen::FRAME_RATE / bpm;
			float subFrac = (float)n.sub / 4;
			float tgSec   = ((n.measure - 1) * beatNum + (n.beat - 1) + subFrac) * secBeat;

			n.frame = (int)(tgSec * Screen::FRAME_RATE);

			notes[noteCount++] = n;
		}
		return true;
	}
};