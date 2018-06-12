#pragma once
#include "stdafx.h"
#include "IPiCounter.h"
#include "CSimplePiCounter.h"
#include "CMultithreadedPiCounter.h"

namespace command_line_tools
{
	const int MAX_ARGUMENT_COUNT = 3;
	const int MIN_ARGUMENT_COUNT = 2;
	const std::string HELP_OPTION = "help";
	const std::string HELP_MESSAGE = "Usage: MonteCarloPiMethod.exe <iterations> <threads>";
	enum class CounterType
	{
		SINGLE,
		MULTI
	};
	struct CommandLineArguments
	{
		size_t iterations;
		size_t threads;
	};
	IPiCounter* GetNeedfulPiCalculatorBy(CounterType calculatorType, CommandLineArguments const & arguments);
}