#pragma once
#include "stdafx.h"
#include "IPiCounter.h"
#include "CMultithreadedPiCounter.h"

namespace command_line_tools
{
	const int ARGUMENT_COUNT = 2;
	const std::string HELP_OPTION = "help";
	const std::string HELP_MESSAGE = "Usage: MonteCarloPiMethod.exe <iterations>";
}