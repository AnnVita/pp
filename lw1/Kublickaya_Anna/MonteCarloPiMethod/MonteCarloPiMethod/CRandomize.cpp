#include "stdafx.h"
#include "CPoint.h"
#include "CRandomize.h"

CRandomize::CRandomize(int minValue, int maxValue)
	: m_distribution(std::uniform_real_distribution<double>(minValue, maxValue))
	, m_generator(m_randomDevice())
{}

double CRandomize::GetNumber()
{
	return m_distribution(m_generator);
}

CPoint CRandomize::GetPoint()
{
	return CPoint(GetNumber(), GetNumber());
}