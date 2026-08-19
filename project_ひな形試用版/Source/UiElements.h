#pragma once
#include <functional>
#include"../Library/GameObject.h"

//Uiをhtmlみたいに実装してみる
//メンバ変数使い方あってるか確認する

using namespace std;

namespace UiFonts{
	static string Archivo = "Archivo Brack";
	static string Inter = "Inter Thin";
}

class UiLabel:public GameObject
{
public:
	UiLabel() {};
	UiLabel(int x, int y, const char* text, int font, int color);
	~UiLabel() { DeleteFontToHandle(m_font); }
	void Draw() override;

	void SetTextColor(int color) { m_color = color; }

private:
	VECTOR2 m_position;
	string m_text;
	int m_font;
	int m_color;
};

class UiButton :public GameObject
{
public:
	UiButton() {};
	UiButton(int x, int y, int h, int w, const char* text, int font, int color);
	~UiButton() { DeleteFontToHandle(m_font); }
	void Update() override;
	void Draw() override;

	void SetText(const char* text) { m_text = text; }
	void SetAction(function<void()> callback) { m_onClick = move(callback); }	 //{ m_onClick = callback; }		
	//関数を入れれる変数型	"function" (voidは変更可能)
	//___SetAction([](){(動作)})___で登録できる
	//[]の中に呼び出し側の変数を入れると、ここでその変数を扱える　<-ガチすげえ
	//functionを引数として扱う場合、move()だと効率的　(値の移し替え)

private:
	VECTOR2 m_position;
	VECTOR2 m_size;
	string m_text;
	int m_font;
	int m_color;

	bool m_isActive = false;
	bool m_isClicked = false;
	bool m_isHovered = false;
	function<void()> m_onClick;
};

class UiBox :public GameObject
{
public:
	UiBox() {};
	UiBox(int x, int y, int h, int w, int color, const char* text = "", int font = -1, int fontColor = -1);
	~UiBox() { DeleteFontToHandle(m_font); }
	void Draw() override;

	void SetBoxColor(int color) { m_color = color; }
	void SetTextColor(int color) { m_fontColor = color; }
	void SetText(const char* text) { m_text = text; }

private:
	VECTOR2 m_position;
	VECTOR2 m_size;
	string m_text;
	int m_font;
	int m_color;
	int m_fontColor;
};

class UiImage :public GameObject
{
public:
	UiImage() {};
	UiImage(int x, int y, int h, int w, int image, int frameColor = -1, int frameThick = 2);
	~UiImage() { DeleteGraph(m_image); }
	void Draw() override;

	void SetImage(int image) {  m_image = image; }

private:
	VECTOR2 m_position;
	VECTOR2 m_size;
	int m_image;
	int m_frameColor;
	int m_frameThick;
};