#include "UiElements.h"
UiBox::UiBox(int x, int y, int w, int h, int color, const char* text, int font, int fontColor)
{
	m_position = VECTOR2(x, y);
	m_size = VECTOR2(w, h);
	m_color = color;
	m_text = text;
	m_font = font;
	m_fontColor = fontColor;
}

void UiBox::Draw()
{
	VECTOR2 topL = VECTOR2(m_position.x, m_position.y);
	VECTOR2 bottomR = VECTOR2(m_position.x + m_size.x, m_position.y + m_size.y);

	int labelW = GetDrawStringWidthToHandle(m_text.c_str(), strlen(m_text.c_str()), m_font);
	int labelH = GetFontSizeToHandle(m_font);

	int drawX = m_position.x + (m_size.x - labelW) / 2;
	int drawY = m_position.y + (m_size.y - labelH) / 2;

	DrawBox(topL.x, topL.y, bottomR.x, bottomR.y, m_color, TRUE);
	DrawStringFToHandle(drawX, drawY, m_text.c_str(), m_fontColor, m_font);
}
