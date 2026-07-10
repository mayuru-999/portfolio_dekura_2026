#pragma once
#include <fstream>
#include <sstream>
#include "Common.h"
#include "../Library/GameObject.h"
using namespace std;

class Loader:public GameObject
{
public:
	float   bpm =	120.0f;	//BPM
	int beatNum =	4;		//拍子(分子)
	int beatDen =	4;		//拍子(分母)

	Common notes[1024];

	bool Load(const char* path) 
	{
		ifstream file(path);
		if (!file.is_open()) return false;

		string line;
		while (getline(file, line))	//一行ずつ見ていく
		{
			if (line.empty() || line[0] == '#') continue; //空白行、#行はスキップ
			istringstream ss(line);
		}
	}
private:

};