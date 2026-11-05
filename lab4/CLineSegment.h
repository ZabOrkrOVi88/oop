#pragma once

#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	static constexpr const char* LINE_SEGMENT_EXPR = "LineSegment: ";
	static constexpr const char* START_EXPR = "start=";
	static constexpr const char* END_EXPR = "end=";
	static constexpr const char* LENGTH_EXPR = "length=";

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	uint32_t GetOutlineColor() const override;
	std::string ToString() const override;

	CLineSegment(const CPoint& startPoint, const CPoint& endPoint, const uint32_t outlineColor);
	CLineSegment(const double startX, const double startY, const double endX, const double endY, const uint32_t outlineColor);

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor;
};