#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	static constexpr const char* CIRCLE_EXPR = "Circle: ";
	static constexpr const char* CENTER_EXPR = "center=";
	static constexpr const char* RADIUS_EXPR = "radius=";

	double GetArea() const override;
	double GetPerimeter() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	CPoint GetCenter() const;
	double GetRadius() const;
	std::string ToString() const override;

	CCircle(const CPoint& center, const double radius, const uint32_t outlineColor, const uint32_t fillColor);
	CCircle(const double& x, const double& y, const double radius, const uint32_t outlineColor, const uint32_t fillColor);

private:
	CPoint m_center;
	double m_radius;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};