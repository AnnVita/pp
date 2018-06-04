#pragma once
#include "stdafx.h"
class CCashier;
class CCustomers
{
public:
	CCustomers(const size_t & number);
	void Wakeup();
	void WaitOnesTurn();
	size_t GetNumber();
	HANDLE GetExitEvent();
	void Action(std::vector<CCashier*> cashiers);
	void GetInLine(std::vector<CCashier*> cashiers);
	~CCustomers();
private:
	size_t number;
	HANDLE wakeupEvent;
	HANDLE exitEvent;
};