#include "CTriangle.h"

CTriangle::CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, const uint32_t outlineColor, const uint32_t fillColor) :
	m_vertex1(vertex1), m_vertex2(vertex2), m_vertex3(vertex3), m_outlineColor(outlineColor), m_fillColor(fillColor)
{
}

CTriangle::CTriangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const uint32_t outlineColor, const uint32_t fillColor) :
	CTriangle(CPoint(x1, y1), CPoint(x2, y2), CPoint(x3, y3), outlineColor, fillColor)
{
}

double CTriangle::GetArea() const
{
	double p = GetPerimeter() * 0.5;
	return sqrt(p * (p - m_vertex1.GetDistance(m_vertex2)) * (p - m_vertex2.GetDistance(m_vertex3)) * (p - m_vertex1.GetDistance(m_vertex3)));
}

double CTriangle::GetPerimeter() const
{
	return m_vertex1.GetDistance(m_vertex2) + m_vertex2.GetDistance(m_vertex3) + m_vertex1.GetDistance(m_vertex3);
}

uint32_t CTriangle::GetOutlineColor() const { return m_outlineColor; }

uint32_t CTriangle::GetFillColor() const { return m_fillColor; }

CPoint CTriangle::GetVertex1() const { return m_vertex1; }

CPoint CTriangle::GetVertex2() const { return m_vertex2; }

CPoint CTriangle::GetVertex3() const { return m_vertex3; }

std::string CTriangle::ToString() const
{
	std::ostringstream oss;
	oss << TRIANGLE_EXPR
		<< VERTICES_EXPR << m_vertex1.ToString() 
		<< SEPARATOR << m_vertex2.ToString() 
		<< SEPARATOR << m_vertex3.ToString() << VERTICES_CLOSE_BRACKET
		<< SEPARATOR << AREA_EXPR << std::fixed << std::setprecision(PRECISION) << GetArea()
		<< SEPARATOR << PERIMETER_EXPR << std::fixed << std::setprecision(PRECISION) << GetPerimeter()
		<< SEPARATOR << OUTLINE_COLOR_EXPR << m_outlineColor
		<< SEPARATOR << FILL_COLOR_EXPR << m_fillColor;

	return oss.str();
}