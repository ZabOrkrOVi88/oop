#pragma once

#include "car.h"

constexpr const char* PROGRAMM_START = "Enter commands (Info, EngineOn, EngineOff, SetGear, SetSpeed):";
constexpr const char* UNKNOWN_COMMAND = "Unknown command";
constexpr const char* INVALID_ARGUMENT = "Invalid command argument";
constexpr const char* ENGINE_ON_ERROR = "Failed to turn on engine. Ensure gear is neutral and speed is 0";
constexpr const char* ENGINE_OFF_ERROR = "Failed to turn off engine. Ensure gear is neutral and speed is 0";
constexpr const char* SET_GEAR_ERROR = "Failed to set gear. Check speed limits or engine state";
constexpr const char* SET_SPEED_ERROR = "Failed to set speed. Check gear limits or engine state";

constexpr const char* ENGINE_EXPR = "Engine: ";
constexpr const char* ON_EXPR = "on";
constexpr const char* OFF_EXPR = "off";
constexpr const char* DIRECTION_EXPR = "Direction: ";
constexpr const char* SPEED_EXPR = "Speed: ";
constexpr const char* GEAR_EXPR = "Gear: ";

constexpr const char* INFO_COMMAND = "Info";
constexpr const char* ENGINE_ON_COMMAND = "EngineOn";
constexpr const char* ENGINE_OFF_COMMAND = "EngineOff";
constexpr const char* SET_GEAR_COMMAND = "SetGear";
constexpr const char* SET_SPEED_COMMAND = "SetSpeed";


enum class Command
{
	UNKNOWN,
	INFO,
	ENGINE_ON,
	ENGINE_OFF,
	SET_GEAR,
	SET_SPEED
};

const std::map<std::string, Command> commandType
{
	{INFO_COMMAND, Command::INFO},
	{ENGINE_ON_COMMAND, Command::ENGINE_ON},
	{ENGINE_OFF_COMMAND, Command::ENGINE_OFF},
	{SET_GEAR_COMMAND, Command::SET_GEAR},
	{SET_SPEED_COMMAND, Command::SET_SPEED}
};

struct InCommand
{
	Command m_type = Command::UNKNOWN;
	std::string m_arg;

	InCommand(const std::string& input);
};

struct CarProcess
{
	void ProcessPrintInfo(const Car& car);
	void ProcessEngineOn(Car& car);
	void ProcessEngineOff(Car& car);
	void ProcessSetGear(Car& car, const std::string gear);
	void ProcessSetSpeed(Car& car, const std::string speed);
	void ProcessCommand(Car& car, const std::string& arg);
	void MainProcess();
};