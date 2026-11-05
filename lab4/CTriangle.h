#pragma once

#include "ISolidShape.h"
#include "CPoint.h"

class CTriangle : public ISolidShape
{
public:
	static constexpr const char* TRIANGLE_EXPR = "Triangle: ";
	static constexpr const char* VERTICES_EXPR = "vertices={";
	static constexpr const char* VERTICES_CLOSE_BRACKET = "}";

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	CPoint GetVertex1() const;
	CPoint GetVertex2() const;
	CPoint GetVertex3() const;

	CTriangle(const CPoint& vertex1, const CPoint& vertex2, const CPoint& vertex3, const uint32_t outlineColor, const uint32_t fillColor);
	CTriangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3, const uint32_t outlineColor, const uint32_t fillColor);

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};