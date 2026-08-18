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
	DrawString(m_position.x, m_position.y, m_text.c_str(), m_color); //c_str()‚Åstring‚ğconst char*‚É•ÏŠ·‚Å‚«‚é‚ç‚µ‚¢->ˆø”‚Íconst char*‚Å‚àŒİŠ·«‚ ‚é‚Ì‚·‚²‚¢‚í
}
