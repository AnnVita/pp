#pragma once
#include "IPiCounter.h"

class CSimplePiCounter : public IPiCounter
{
public:
	CSimplePiCounter(size_t iterations);
	double CountPi() override;
private:
	size_t m_iterations;
};