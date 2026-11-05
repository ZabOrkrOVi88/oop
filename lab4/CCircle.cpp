#include "CCircle.h"

CCircle::CCircle(const CPoint& center, const double radius, const uint32_t outlineColor, const uint32_t fillColor) :
	m_center(center), m_radius(radius), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
	if (m_radius < 0) { m_radius = 0; }
}

CCircle::CCircle(const double& x, const double& y, const double radius, const uint32_t outlineColor, const uint32_t fillColor) :
	CCircle(CPoint(x, y), radius, outlineColor, fillColor)
{
}

double CCircle::GetArea() const { return M_PI * m_radius * m_radius; }

double CCircle::GetPerimeter() const { return 2 * M_PI * m_radius; }

uint32_t CCircle::GetOutlineColor() const { return m_outlineColor; }

uint32_t CCircle::GetFillColor() const { return m_fillColor; }

CPoint CCircle::GetCenter() const { return m_center; }

double CCircle::GetRadius() const { return m_radius; }

std::string CCircle::ToString() const
{
	std::ostringstream oss;
	oss << CIRCLE_EXPR
		<< CENTER_EXPR << m_center.ToString()
		<< SEPARATOR << RADIUS_EXPR << std::fixed << std::setprecision(PRECISION) << m_radius
		<< SEPARATOR << AREA_EXPR << std::fixed << std::setprecision(PRECISION) << GetArea()
		<< SEPARATOR << PERIMETER_EXPR << std::fixed << std::setprecision(PRECISION) << GetPerimeter()
		<< SEPARATOR << OUTLINE_COLOR_EXPR << m_outlineColor
		<< SEPARATOR << FILL_COLOR_EXPR << m_fillColor;

	return oss.str();
}