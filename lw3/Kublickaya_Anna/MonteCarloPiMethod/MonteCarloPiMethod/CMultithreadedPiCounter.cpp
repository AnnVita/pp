#include "stdafx.h"
#include "CMultithreadedPiCounter.h"
#include "CRandomize.h"

CMultithreadedPiCounter::CMultithreadedPiCounter(size_t countIterations)
	: m_countIterations(countIterations)
	, m_random(std::make_shared<CRandomize>(-m_CIRCLE_RADIUS, m_CIRCLE_RADIUS))
{
}

double CMultithreadedPiCounter::CountPi()
{
	int countPointsInCircle = GetCountPointsInCircle(m_countIterations);
	return 4.0 * countPointsInCircle / m_countIterations;
}

bool CMultithreadedPiCounter::IsPointInCircle(CPoint const& point)
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= m_CIRCLE_RADIUS;
}

size_t CMultithreadedPiCounter::GetCountPointsInCircle(int countIterations)
{
	#pragma omp parallel for
	for (int i = 0; i < countIterations; ++i)
	{
		CPoint point = m_random->GetPoint();

		if (IsPointInCircle(point))
		{
			#pragma omp atomic
			++m_countPointInCircle;
		}
	}
	return m_countPointInCircle;
}