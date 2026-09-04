#include "UiElements.h"

UiLabel::UiLabel(int x, int y, const char* text, int font, int color)
{
	m_position = VECTOR2(x, y);
	m_text = text;
	m_font = font;
	m_color = color;
}

void UiLabel::Draw()
{
	DrawStringFToHandle(m_position.x, m_position.y, m_text.c_str(), m_color, m_font);
}
