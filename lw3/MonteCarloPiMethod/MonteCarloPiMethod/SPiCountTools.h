#pragma once
#include "CPoint.h"

class SPiCountTools
{
public:
	static bool IsPointInsideCircle(CPoint const & point);
	static size_t GetCountPointsInsideCircle(size_t iterations);
private:
	static const int m_CIRCLE_RADIUS = 1;
};