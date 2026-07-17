#pragma once
class Common
{
public:
	enum HitType
	{
		Excellent,
		Good,
		Hit,
		Miss,
		HitType_MAX,
	};
	const int HitThreshold[HitType_MAX]
	{
		3, //Excellent
		6, //Good
		9, //Hit
		12  //Miss
	};
	struct NoteData
	{
		int measure;		//小節　　　　	  例：１小節目の
		int beat;			//拍中の分子		：１/
		int sub;			//　〃　分母		： /４の位置
		int lane;			//レーンの位置
		int frame;			//判定到達までのフレーム
	};
private:

};