#include "stdafx.h"
#include "NCommandLineTools.h"

namespace command_line_tools
{
	IPiCounter* GetNeedfulPiCalculatorBy(CounterType counterType, CommandLineArguments const & arguments)
	{
		if (CounterType::MULTI == counterType)
		{
			return new CMultithreadedPiCounter(arguments.iterations, arguments.threads);
		}
		else
		{
			return new CSimplePiCounter(arguments.iterations);
		}
	}
}