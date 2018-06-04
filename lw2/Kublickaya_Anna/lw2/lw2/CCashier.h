#pragma once
#include "stdafx.h"
#include "CCustomer.h"

class CCashier
{
public:
	CCashier(const size_t & number);
	void ServeCustomer();
	void ServeCustomers();
	void AddCustomerInQueue(CCustomer * customer);
	void StopWorking();
	size_t GetNumber();
	~CCashier();
private:
	HANDLE semaphore;
	std::queue<CCustomer *> queue;
	size_t number;
	static const size_t clientsBufferSize = 10;
	bool isWorking = true;
};