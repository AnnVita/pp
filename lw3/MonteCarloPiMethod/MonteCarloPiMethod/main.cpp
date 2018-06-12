#include "stdafx.h"
#include "IPiCounter.h"
#include "CSimplePiCounter.h"
//#include "SingleThreadedPiCalculator.h"

using namespace command_line_tools;

int main(int argc, char *argv[])
{
	try
	{
		if (argc != MAX_ARGUMENT_COUNT)
		{
			throw std::invalid_argument(HELP_MESSAGE);
		}
		CommandLineArguments arguments;
		arguments.iterations = std::stoi(argv[1]);
		arguments.threads = std::stoi(argv[2]);
		CounterType counterType = (arguments.threads > 1) ? CounterType::MULTI : CounterType::SINGLE;

		unsigned int startTime = clock();
		IPiCounter* piCounter = GetNeedfulPiCalculatorBy(counterType, arguments);

		std::cout << "Selected type: " << ((counterType == CounterType::MULTI) ? "multithread" : "simple") << std::endl;
		std::cout << "Result Pi : " << piCounter->CountPi() << std::endl;
		unsigned int endTime = clock();
		std::cout << "Counting time : " << (static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC) << std::endl;
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}