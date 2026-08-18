#include "UiElements.h"	

UiButton::UiButton(int x, int y, int h, int w, const char* text, int font, int color)
{
	m_position = VECTOR2(x, y);
	m_size = VECTOR2(w, h);
	m_text = text;
	m_font = font;
	m_color = color;
}
void UiButton::Update()
{
	m_isHovered = false;

	int x, y;
	GetMousePoint(&x, &y);
	if (m_position.x >= x >= m_position.x + m_size.x) {
		if (m_position.y >= y >= m_position.y + m_size.y) {
			m_isHovered = true;
		}
	}

	if (GetMouseInput() & MOUSE_INPUT_LEFT) {
		if (!m_isClicked) {
			if (m_onClick) m_onClick();
			m_isClicked = true;
		}
	}
	else m_isClicked = false;

}
void UiButton::Draw()
{


	DrawBox(m_position.x, m_position.y, m_position.x + m_size.x, m_position.y + m_size.y, GetColor(255, 255, 255), TRUE);
	DrawString(m_position.x + 10, m_position.y + 10, m_text.c_str(), m_color);
}
