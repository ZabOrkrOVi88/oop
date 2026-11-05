#pragma once

#include "ISolidShape.h"
#include "CPoint.h"

class CRectangle : public ISolidShape
{
public:
	static constexpr const char* RECTANGLE_EXPR = "Rectangle: ";
	static constexpr const char* LEFT_TOP_EXPR = "leftTop=";
	static constexpr const char* RIGHT_BOTTOM_EXPR = "rightBottom=";
	static constexpr const char* WIDTH_EXPR = "width=";
	static constexpr const char* HEIGHT_EXPR = "height=";

	double GetArea() const override;
	double GetPerimeter() const override;
	double GetWidth() const;
	double GetHeight() const;
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;
	std::string ToString() const override;

	CRectangle(const CPoint& leftTop, const CPoint& rightBottom, const uint32_t outlineColor, const uint32_t fillColor);
	CRectangle(const double x1, const double y1, const double x2, const double y2, const uint32_t outlineColor, const uint32_t fillColor);

private:
	CPoint m_leftTop;
	CPoint m_rightBottom;
	double m_width;
	double m_height;
	uint32_t m_outlineColor;
	uint32_t m_fillColor;
};