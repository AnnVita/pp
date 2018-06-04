#include "stdafx.h"
#include "CRandomize.h"

CRandomize::CRandomize(int minValue, int maxValue)
	: m_distribution(std::uniform_int_distribution<int>(minValue, maxValue))
	, m_generator(m_randomDevice())
{}

int CRandomize::GetNumber()
{
	return m_distribution(m_generator);
}