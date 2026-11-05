#include "CPoint.h"

CPoint::CPoint(const double& x, const double& y) : m_x(x), m_y(y) {}

double CPoint::GetDistance(const CPoint other) const
{
	double x = m_x - other.m_x;
	double y = m_y - other.m_y;

	return std::sqrt(x * x + y * y);
}

std::string CPoint::ToString() const
{
	std::ostringstream oss;
	oss << OPEN_BRACKET << std::fixed << std::setprecision(PRECISION) << m_x << SEPARATOR << m_y << CLOSE_BRACKET;
	
	return oss.str();
}