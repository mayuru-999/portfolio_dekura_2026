#include "UiElements.h"
#include "Score.h"

UiResult::UiResult(int x, int y, int h, int w, int frameColor, int frameThick)
{
	m_position = VECTOR2(x, y);
	m_size = VECTOR2(w, h);
	m_frameColor = frameColor;
	m_frameThick = frameThick;

    m_font = CreateFontToHandle(UiFonts::Inter.c_str(), 24, -1);
}
void UiResult::Draw()
{
    VECTOR2 topL = VECTOR2(m_position.x, m_position.y);
    VECTOR2 topR = VECTOR2(m_position.x + m_size.x, m_position.y);
    VECTOR2 bottomL = VECTOR2(m_position.x, m_position.y + m_size.y);
    VECTOR2 bottomR = VECTOR2(m_position.x + m_size.x, m_position.y + m_size.y);
    int r = m_frameThick / 2;

    DrawBox(topL.x, topL.y, bottomR.x, bottomR.y, 0xE6E6E6, TRUE);

    if (m_frameColor != -1) {
        DrawLine(topL.x, topL.y, topR.x, topR.y, m_frameColor, m_frameThick);
        DrawLine(topL.x, topL.y, bottomL.x, bottomL.y, m_frameColor, m_frameThick);
        DrawLine(topR.x, topR.y, bottomR.x, bottomR.y, m_frameColor, m_frameThick);
        DrawLine(bottomL.x, bottomL.y, bottomR.x, bottomR.y, m_frameColor, m_frameThick);
        DrawCircle(topL.x, topL.y, r, m_frameColor, TRUE);
        DrawCircle(topR.x, topR.y, r, m_frameColor, TRUE);
        DrawCircle(bottomL.x, bottomL.y, r, m_frameColor, TRUE);
        DrawCircle(bottomR.x, bottomR.y, r, m_frameColor, TRUE);
    }

    Score::JudgeScore result = s.getResult();

	DrawFormatStringToHandle(topL.x + 10, topL.y + 10,  GetColor(0, 0, 0), m_font, "_RESULT_");

	DrawFormatStringToHandle(topL.x + 10, topL.y + 50,  GetColor(0, 0, 0), m_font, "COMBO : %d", s.maxCombo);
	DrawFormatStringToHandle(topL.x + 10, topL.y + 70,  GetColor(0, 0, 0), m_font, "SCORE : %d", s.score);

	DrawFormatStringToHandle(topL.x + 10, topL.y + 100, GetColor(0, 0, 0), m_font, "EXCELLENT :%d", result.excellent);
	DrawFormatStringToHandle(topL.x + 10, topL.y + 120, GetColor(0, 0, 0), m_font, "GOOD      :%d", result.good);
	DrawFormatStringToHandle(topL.x + 10, topL.y + 140, GetColor(0, 0, 0), m_font, "HIT       :%d", result.hit);
	DrawFormatStringToHandle(topL.x + 10, topL.y + 160, GetColor(0, 0, 0), m_font, "MISS      :%d", result.miss);

	DrawFormatStringToHandle(topL.x + 10, topL.y + 200, GetColor(0, 0, 0), m_font, "PLESS_SPACE");
}