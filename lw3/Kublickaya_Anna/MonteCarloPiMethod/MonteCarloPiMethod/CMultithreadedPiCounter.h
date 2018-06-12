#pragma once
#include "stdafx.h"
#include "CPoint.h"
#include "IPiCounter.h"
#include "CThreadHandler.h"

struct ThreadResult
{
	size_t countPointsInCircle;
	size_t countIterations;
};

using ThreadResults = std::vector<ThreadResult>;

class CMultithreadedPiCounter : public IPiCounter
{
public:
	CMultithreadedPiCounter(size_t countIterations, size_t countThreads);
	double CountPi() override;
private:
	size_t m_countIterations;
	size_t m_countThreads;

	static DWORD WINAPI GetCountPointsInCircle(LPVOID lpParam);
	void InitThreads();

	std::shared_ptr<CThreadHandler> m_threadHandler;
	std::vector<ThreadResult> m_threadResults;
};
