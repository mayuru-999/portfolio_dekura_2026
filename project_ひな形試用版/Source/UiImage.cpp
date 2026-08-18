#include "UiElements.h"

UiImage::UiImage(int x, int y, int h, int w, int image, int frameColor)
{
	m_position = VECTOR2(x, y);
	m_size = VECTOR2(h, w);
	m_image = image;
    m_frameColor = frameColor;
}
void UiImage::Draw()
{
    if (m_image != -1)
        DrawExtendGraph(m_position.x, m_position.y, m_position.x + m_size.x, m_position.y + m_size.y, m_image, TRUE);
    else
        DrawBox(m_position.x, m_position.y, m_position.x + m_size.x, m_position.y + m_size.y, 0xE6E6E6, TRUE);// 未ロードのときはグレー一色

    if (m_frameColor != NULL)
        DrawBox(m_position.x, m_position.y, m_position.x + m_size.x, m_position.y + m_size.y, m_frameColor, FALSE); //枠
}
