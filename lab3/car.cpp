#include <iostream>
#include "car.h"


bool Car::IsTurnedOn() const { return m_isTurnedOn; }

std::string Car::GetDirection() const
{
	switch (m_direction)
	{
	case Direction::STANDING_STILL: return STANDING_STILL_EXPR;
	case Direction::FORWARD: return FORWARD_EXPR;
	case Direction::BACKWARD: return BACKWARD_EXPR;
	}
}

int Car::GetSpeed() const { return m_speed; }

int Car::GetGear() const { return m_gear; }

bool Car::TurnOnEngine()
{
	if (m_isTurnedOn) { return true; }

	if (m_gear == 0 && m_speed == MIN_SPEED)
	{
		m_isTurnedOn = true;
		return true;
	}
	return false;
}

bool Car::TurnOffEngine()
{
	if ((m_isTurnedOn && m_gear == 0 && m_speed == MIN_SPEED) || !m_isTurnedOn)
	{
		m_isTurnedOn = false;
		return true;
	}
	else { return false; }
}

bool Car::SetGear(int gear)
{
	if (gear == m_gear) { return true; }

	if (!m_isTurnedOn) { return false; }

	if (gear < MIN_GEAR || gear > MAX_GEAR) { return false; }

	if (gear == MIN_GEAR && m_speed != MIN_SPEED) { return false; }

	if (m_gear == MIN_GEAR && gear != 0) { return false; }

	if (m_gear == 0 && m_direction == Direction::BACKWARD) { return false; }

	const auto range = gearRange.find(gear)->second;

	if (range.first <= m_speed && range.second >= m_speed)
	{
		m_gear = gear;
		return true;
	}
	else
	{
		return false;
	}
}

bool Car::SetSpeed(int speed)
{
	if (speed == m_speed) { return true; }

	if (speed < MIN_SPEED || speed > MAX_SPEED) { return false; }

	if (m_gear == 0 && speed > m_speed) { return false; }

	const auto range = gearRange.find(m_gear)->second;

	if (range.first <= speed && range.second >= speed)
	{
		m_speed = speed;
		setDirection();
		return true;
	}
	else
	{
		return false;
	}
}

void Car::setDirection()
{
	if (m_speed == MIN_SPEED) { m_direction = Direction::STANDING_STILL; }

	else if (m_gear == MIN_GEAR && m_speed > MIN_SPEED) { m_direction = Direction::BACKWARD; }

	else if (m_gear > MIN_GEAR && m_speed > MIN_SPEED && m_direction != Direction::BACKWARD) { m_direction = Direction::FORWARD; }
}