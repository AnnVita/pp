#pragma once

class CRandomize
{
public:
	CRandomize(int min, int max);
	double GetNumber();
	CPoint GetPoint();
private:
	std::default_random_engine m_generator;
	std::uniform_real_distribution<double> m_distribution;
	std::random_device m_randomDevice;
};