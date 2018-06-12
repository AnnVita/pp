#include "stdafx.h"
#include "CSimplePiCounter.h"

CSimplePiCounter::CSimplePiCounter(size_t iterations)
	: m_iterations(iterations)
{}

double CSimplePiCounter::CountPi()
{
	size_t countPointsInCircle = SPiCountTools::GetCountPointsInsideCircle(m_iterations);
	return 4.0 * countPointsInCircle / m_iterations;
}
