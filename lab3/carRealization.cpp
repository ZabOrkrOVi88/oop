#include <sstream>
#include <iostream>
#include "carRealization.h"

InCommand::InCommand(const std::string& input)
{
	std::istringstream stream(input);
	std::string cmdStr;

	if (stream >> cmdStr)
	{
		auto it = commandType.find(cmdStr);
		if (it != commandType.end())
		{
			m_type = it->second;

			if (m_type == Command::SET_GEAR || m_type == Command::SET_SPEED)
			{
				stream >> m_arg;
			}
		}
	}
}

void CarProcess::ProcessPrintInfo(const Car& car)
{
	std::cout << ENGINE_EXPR << (car.IsTurnedOn() ? ON_EXPR : OFF_EXPR) << "\n";
	std::cout << DIRECTION_EXPR << car.GetDirection() << "\n";
	std::cout << SPEED_EXPR << car.GetSpeed() << "\n";
	std::cout << GEAR_EXPR << car.GetGear() << "\n";
}

void CarProcess::ProcessEngineOn(Car& car)
{
	if (!car.TurnOnEngine())
	{
		std::cout << ENGINE_ON_ERROR << "\n";
	}
}

void CarProcess::ProcessEngineOff(Car& car)
{
	if (!car.TurnOffEngine())
	{
		std::cout << ENGINE_OFF_ERROR << "\n";
	}
}

void CarProcess::ProcessSetGear(Car& car, const std::string gear)
{
	try
	{
		int arg = std::stoi(gear);

		if (!car.SetGear(arg))
		{
			std::cout << SET_GEAR_ERROR << "\n";
		}
	}
	catch (const std::exception&)
	{
		std::cout << INVALID_ARGUMENT << "\n";
	}
}

void CarProcess::ProcessSetSpeed(Car& car, const std::string speed)
{
	try
	{
		int arg = std::stoi(speed);

		if (!car.SetSpeed(arg))
		{
			std::cout << SET_SPEED_ERROR << "\n";
		}
	}
	catch (const std::exception&)
	{
		std::cout << INVALID_ARGUMENT << "\n";
	}
}

void CarProcess::ProcessCommand(Car& car, const std::string& input)
{
	InCommand command(input);
	switch (command.m_type)
	{
	case Command::UNKNOWN:
		std::cout << UNKNOWN_COMMAND << "\n";
		break;

	case Command::INFO:
		ProcessPrintInfo(car);
		break;

	case Command::ENGINE_ON:
		ProcessEngineOn(car);
		break;

	case Command::ENGINE_OFF:
		ProcessEngineOff(car);
		break;

	case Command::SET_GEAR:
		ProcessSetGear(car, command.m_arg);
		break;

	case Command::SET_SPEED:
		ProcessSetSpeed(car, command.m_arg);
		break;
	}
};

void CarProcess::MainProcess()
{
	Car car;
	std::string buff;

	std::cout << PROGRAMM_START << "\n";

	while (std::getline(std::cin, buff))
	{
		if (buff.empty()) continue;
		ProcessCommand(car, buff);
	}
}