#pragma once
#include "stdafx.h"
#include "CPoint.h"
#include "IPiCounter.h"
#include "CThreadHandler.h"
#include "CRandomize.h"

struct ThreadResult
{
	size_t countPointsInCircle;
	size_t countIterations;
};

using ThreadResults = std::vector<ThreadResult>;

class CMultithreadedPiCounter : public IPiCounter
{
public:
	CMultithreadedPiCounter(size_t countIterations);
	double CountPi() override;
private:
	bool IsPointInCircle(CPoint const & point);
	size_t GetCountPointsInCircle(int countIterations);

	size_t m_countIterations;
	int m_countPointInCircle = 0;
	std::shared_ptr<CRandomize> m_random;

	static const int m_CIRCLE_RADIUS = 1;
};
