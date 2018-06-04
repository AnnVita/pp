#pragma once
#include "stdafx.h"

class CRandomize
{
public:
	CRandomize(int min, int max);
	int GetNumber();
private:
	std::default_random_engine m_generator;
	std::uniform_int_distribution<int> m_distribution;
	std::random_device m_randomDevice;
};