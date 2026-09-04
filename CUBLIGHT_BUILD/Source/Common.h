#pragma once
#include <string>
#include "Screen.h"
#include "GameOption.h"
using namespace std;

class Common
{
public:
	enum HitType
	{
		Excellent,
		Good,
		Hit,
		Miss,
		NoHit,
	};
	const int HitThreshold[4]
	{
		1,  //Excellent
		2,  //Good
		4,  //Hit
		6  //Miss
	};
	static inline float HitScore[4]
	{
		1000,  //Excellent
		70,   //Good
		50,   //Hit
		0,    //Miss
	};
	struct NoteData
	{
		int measure;		//小節　　　　	  例：１小節目の
		int beat;			//拍中の分子		：１/
		int sub;			//　〃　分母		： /４の位置
		int lane;			//レーンの位置
		float timing;		//初期のノーツ位置
	};
	struct SongData 
	{
		string name;		// 曲名
		string csvPath;		// chart.csv のパス
		string bgmPath;		// bgmファイルのパス
		int songImage;      //サムネ画像
	};

	float judgeLine = 600.0f;			//判定ラインの位置
	float laneCount = 12.0f;			//レーンの数
	float laneSpace = 74.0f;			//レーンの幅
	float noteMargin = 5.0f;			//レーンとノーツの余白
	float laneLeftPosition = 191.0f;	//レーンの左端の位置
	float laneRightPosition = laneLeftPosition + (laneSpace * laneCount);	//レーンの右端の位置

	float startDiray = 3.0f;		//ゲーム開始までのディレイ(秒)
	float maxScore = 1010000.0f;	//最大スコア
};