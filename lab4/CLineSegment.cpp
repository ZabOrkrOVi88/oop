#include "CLineSegment.h"

CLineSegment::CLineSegment(const CPoint& startPoint, const CPoint& endPoint, const uint32_t outlineColor)
	: m_startPoint(startPoint), m_endPoint(endPoint), m_outlineColor(outlineColor)
{
}

CLineSegment::CLineSegment(const double startX, const double startY, const double endX, const double endY, const uint32_t outlineColor)
	: CLineSegment(CPoint(startX, startY), CPoint(endX, endY), outlineColor)
{
}

CPoint CLineSegment::GetStartPoint() const { return m_startPoint; }

CPoint CLineSegment::GetEndPoint() const { return m_endPoint; }

double CLineSegment::GetArea() const { return 0; }

double CLineSegment::GetPerimeter() const { return m_startPoint.GetDistance(m_endPoint); }

uint32_t CLineSegment::GetOutlineColor() const { return m_outlineColor; }

std::string CLineSegment::ToString() const
{
	std::ostringstream oss;
	oss << LINE_SEGMENT_EXPR
		<< START_EXPR << m_startPoint.ToString()
		<< SEPARATOR << END_EXPR << m_endPoint.ToString()
		<< SEPARATOR << LENGTH_EXPR << std::fixed << std::setprecision(PRECISION) << GetPerimeter()
		<< SEPARATOR << OUTLINE_COLOR_EXPR << m_outlineColor;

	return oss.str();
}