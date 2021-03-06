#include "stdafx.h"
#include "Bee.h"
#include "Bear.h"
#include "Pot.h"
#include "ThreadPool.h"
#include "Event.h"
#include "Semaphore.h"

/*
Задача о Винни-Пухе или правильные пчелы (Вариант 2)
В одном лесу живут M пчел и один медведь, которые используют один горшок меда
вместимостью N глотков. Сначала горшок пустой. Пока горшок не наполнится,
медведь спит. Как только горшок заполняется, медведь просыпается и съедает весь мед,
после чего снова засыпает. Каждая пчела многократно собирает по одному глотку меда
и кладет его в горшок. Пчела, которая приносит последнюю порцию меда, будит медведя.
Условную синхронизацию потоков выполнить с помощью событий и семафоров.

Программа принимает либо 1 ключ для запуска --help, либо два числа: кол-во пчёл и
вместимость горшка
*/

namespace
{
void SimulateBeeGardenBehavior(unsigned beesCount, unsigned potCapacity)
{
	auto wakeBearEvent = std::make_shared<Event>(false); // вначале медведь спит
	auto wakeBeesEvent = std::make_shared<Event>(true); // а пчёлы носят мёд
	auto beesPotAccessSemaphore = std::make_shared<Semaphore>(1u, 1u);

	Pot pot(potCapacity);
	Bear bear(pot, wakeBearEvent, wakeBeesEvent);

	std::vector<std::unique_ptr<Bee>> bees;
	bees.reserve(beesCount);

	unsigned i = 0u;
	while (i++ < beesCount)
	{
		bees.push_back(std::make_unique<Bee>(i, pot, wakeBearEvent, wakeBeesEvent, beesPotAccessSemaphore));
	}

	ThreadPool threads(bees.size() + 1u);
	for (auto& bee : bees)
	{
		threads.Add([&bee]() { bee->GatherAndStoreHoney(); });
	}
	threads.Add([&bear]() { bear.EatHoney(); });
	threads.Join();
}

void ExecuteApplication(std::vector<std::string> && args)
{
	const unsigned beesCount = std::stoul(args[1]);
	const unsigned potCapacity = std::stoul(args[2]);
	SimulateBeeGardenBehavior(beesCount, potCapacity);
}

void PrintUsageInstructions(std::ostream& strm)
{
	strm << "Usage: RegularBees.exe <bees count> <pot capacity>" << std::endl;
}
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc == 2 && strcmp(argv[1], "--help") == 0)
		{
			PrintUsageInstructions(std::cout);
		}
		else if (argc == 3)
		{
			ExecuteApplication(std::vector<std::string>(argv, argv + argc));
		}
		else
		{
			std::cerr << "Invalid arguments count!" << std::endl;
			PrintUsageInstructions(std::cerr);
			return 1;
		}
	}
	catch (const std::exception& ex)
	{
		std::cerr << ex.what() << std::endl;
		return 1;
	}
	return 0;
}
