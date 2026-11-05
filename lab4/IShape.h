#pragma once

#include <string>

class IShape
{
public:
	static constexpr const char* SEPARATOR = ", ";
	static constexpr const char* AREA_EXPR = "area=";
	static constexpr const char* PERIMETER_EXPR = "perimeter=";
	static constexpr const char* OUTLINE_COLOR_EXPR = "outlineColor=";
	static constexpr int PRECISION = 2;

	virtual ~IShape() = default;

	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
	virtual std::string ToString() const = 0;

};