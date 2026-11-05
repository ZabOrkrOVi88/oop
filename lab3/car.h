#pragma once

#include <map>
#include <utility>
#include <string>

const int MIN_GEAR = -1;
const int MAX_GEAR = 5;
const int MIN_SPEED = 0;
const int MAX_SPEED = 150;

constexpr const char* STANDING_STILL_EXPR = "standing_still";
constexpr const char* FORWARD_EXPR = "forward";
constexpr const char* BACKWARD_EXPR = "backward";

const std::map<int, std::pair<int, int>> gearRange
{
	{-1, {0, 20}},
	{0, {0, 150}},
	{1, {0, 30}},
	{2, {20, 50}},
	{3, {30, 60}},
	{4, {40, 90}},
	{5, {50, 150}},
};


enum class Direction
{
	STANDING_STILL,
	FORWARD,
	BACKWARD
};

class Car
{
public:
	bool IsTurnedOn() const;
	std::string GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;

	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	int m_gear = 0;
	int m_speed = MIN_SPEED;
	bool m_isTurnedOn = false;
	Direction m_direction = Direction::STANDING_STILL;
	void setDirection();
};