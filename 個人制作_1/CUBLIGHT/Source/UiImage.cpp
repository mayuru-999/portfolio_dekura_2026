#include "UiElements.h"

UiImage::UiImage(int x, int y, int h, int w, int image, int frameColor, int frameThick)
{
	m_position = VECTOR2(x, y);
	m_size = VECTOR2(h, w);
	m_image = image;
    m_frameColor = frameColor;
    m_frameThick = frameThick;
}
void UiImage::Draw()
{
    VECTOR2 topL    = VECTOR2(m_position.x, m_position.y);
    VECTOR2 topR    = VECTOR2(m_position.x + m_size.x, m_position.y);
    VECTOR2 bottomL = VECTOR2(m_position.x, m_position.y + m_size.y);
    VECTOR2 bottomR = VECTOR2(m_position.x + m_size.x, m_position.y + m_size.y);
    int r = m_frameThick / 2;

    if (m_image != -1)
        DrawExtendGraph(topL.x, topL.y, bottomR.x, bottomR.y, m_image, TRUE);
    else
        DrawBox(topL.x, topL.y, bottomR.x, bottomR.y, 0xE6E6E6, TRUE);// 未ロードのときはグレー一色

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
}
