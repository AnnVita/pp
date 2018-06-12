#include "stdafx.h"
#include "IPiCounter.h"

using namespace command_line_tools;

int main(int argc, char *argv[])
{
	try
	{
		if (argc < ARGUMENT_COUNT)
		{
			throw std::invalid_argument(HELP_MESSAGE);
		}
		int countIterations = std::stoi(argv[1]);

		unsigned int startTime = clock();
		CMultithreadedPiCounter monteCarloMethod(countIterations);

		std::cout << "Result Pi : " << monteCarloMethod.CountPi() << std::endl;
		unsigned int endTime = clock();
		std::cout << "Counting time : " << (static_cast<float>(endTime - startTime) / CLOCKS_PER_SEC) << std::endl;
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}

	return 0;
}