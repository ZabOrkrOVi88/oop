#pragma once

#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

class CPoint
{
public:
	static constexpr const char* SEPARATOR = ", ";
	static constexpr const char* OPEN_BRACKET = "(";
	static constexpr const char* CLOSE_BRACKET = ")";
	static constexpr int PRECISION = 2;

	double m_x = 0;
	double m_y = 0;

	double GetDistance(const CPoint other) const;
	std::string ToString() const;

	CPoint(const double& x, const double& y);
};