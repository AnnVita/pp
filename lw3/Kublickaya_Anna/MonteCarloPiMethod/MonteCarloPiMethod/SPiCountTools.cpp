#include "stdafx.h"
#include "CPoint.h"
#include "SPiCountTools.h"
#include "CRandomize.h"

bool SPiCountTools::IsPointInsideCircle(CPoint const& point)
{
	return point.GetX() * point.GetX() + point.GetY() * point.GetY() <= m_CIRCLE_RADIUS;
}

size_t SPiCountTools::GetCountPointsInsideCircle(size_t iterations)
{
	CRandomize random(-m_CIRCLE_RADIUS, m_CIRCLE_RADIUS);
	size_t result = 0;
	for (size_t i = 0; i < iterations; ++i)
	{
		CPoint point = random.GetPoint();
		if (IsPointInsideCircle(point))
		{
			++result;
		}
	}
	return result;
}