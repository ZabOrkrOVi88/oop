#include "CRectangle.h"

CRectangle::CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const uint32_t outlineColor, const uint32_t fillColor) :
	m_leftTop(leftTop), m_rightBottom(rightBottom), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	m_width = abs(m_rightBottom.m_x - m_leftTop.m_x);
	m_height = abs(m_leftTop.m_y - m_rightBottom.m_y);
}

CRectangle::CRectangle(const double x1, const double y1, const double x2, const double y2, const uint32_t outlineColor, const uint32_t fillColor) :
	CRectangle(CPoint(x1, y1), CPoint(x2, y2), outlineColor, fillColor)
{
}

double CRectangle::GetArea() const { return m_width * m_height; }

double CRectangle::GetPerimeter() const { return 2 * (m_width + m_height); }

double CRectangle::GetWidth() const { return m_width; }

double CRectangle::GetHeight() const { return m_height; }

CPoint CRectangle::GetLeftTop() const { return m_leftTop; }

CPoint CRectangle::GetRightBottom() const { return m_rightBottom; }

uint32_t CRectangle::GetOutlineColor() const { return m_outlineColor; }

uint32_t CRectangle::GetFillColor() const { return m_fillColor; }

std::string CRectangle::ToString() const
{
	std::ostringstream oss;
	oss << RECTANGLE_EXPR
		<< LEFT_TOP_EXPR << m_leftTop.ToString()
		<< SEPARATOR << RIGHT_BOTTOM_EXPR << m_rightBottom.ToString()
		<< SEPARATOR << WIDTH_EXPR << std::fixed << std::setprecision(PRECISION) << m_width
		<< SEPARATOR << HEIGHT_EXPR << std::fixed << std::setprecision(PRECISION) << m_height
		<< SEPARATOR << AREA_EXPR << std::fixed << std::setprecision(PRECISION) << GetArea()
		<< SEPARATOR << PERIMETER_EXPR << std::fixed << std::setprecision(PRECISION) << GetPerimeter()
		<< SEPARATOR << OUTLINE_COLOR_EXPR << m_outlineColor
		<< SEPARATOR << FILL_COLOR_EXPR << m_fillColor;

	return oss.str();
}