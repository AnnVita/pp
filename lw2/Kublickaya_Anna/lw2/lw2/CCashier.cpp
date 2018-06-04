#include "stdafx.h"
#include "CCashier.h"
#include "CCustomer.h"
#include "CRandomize.h"

CCashier::CCashier(const size_t &number)
{
	this->number = number;
	semaphore = CreateSemaphore(NULL, 0, clientsBufferSize, NULL);
}

void CCashier::ServeCustomer()
{
	CRandomize random(3000, 5000);
	int sleepTime = random.GetNumber();
	Sleep(sleepTime);
	auto customer = queue.front();
	customer->Wakeup();
	std::cout << "Customer No: " + std::to_string(customer->GetNumber()) + " served in cashdesk: " + std::to_string(number) + '\n';
	std::cout << "Serving time: " + std::to_string(sleepTime) + "\n\n";
	WaitForSingleObject(customer->GetExitEvent(), INFINITE);
	queue.pop();
}

size_t CCashier::GetNumber()
{
	return number;
}

void CCashier::ServeCustomers()
{
	while (true)
	{
		if (!isWorking && queue.empty())
		{
			break;
		}
		if (queue.empty())
		{
			std::cout << "Cashier No: " + std::to_string(number) + " is sleeping now\n";
		}
		WaitForSingleObject(semaphore, INFINITE);
		ServeCustomer();
	}
	std::cout << "Cashdesk " + std::to_string(number) + " closed\n";
}

void CCashier::AddCustomerInQueue(CCustomer* customer)
{
	std::string msg = "New customer " + std::to_string(customer->GetNumber()) + " arrived on cashdesk No: " + std::to_string(number) + '\n';
	std::cout << msg;
	queue.push(customer);
	ReleaseSemaphore(semaphore, 1, NULL);
}

void CCashier::StopWorking()
{
	isWorking = false;
}

CCashier::~CCashier()
{
	CloseHandle(semaphore);
}