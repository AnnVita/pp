#include "stdafx.h"
#include "CCustomer.h"
#include "CCashier.h"
#include "CRandomize.h"

CCustomers::CCustomers(const size_t & number)
{
	this->number = number;
	wakeupEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	exitEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
}

void CCustomers::Wakeup()
{
	SetEvent(wakeupEvent);
}

size_t CCustomers::GetNumber()
{
	return number;
}

void CCustomers::GetInLine(std::vector<CCashier*> cashiers)
{
	CRandomize random(0, cashiers.size() - 1);
	int cashierNumber = random.GetNumber();
	cashiers[cashierNumber]->AddCustomerInQueue(this);
}

void CCustomers::Action(std::vector<CCashier*> cashiers)
{
	CRandomize random(1000, 15000);
	int sleepTime = random.GetNumber();
	Sleep(sleepTime);
	GetInLine(cashiers);
	WaitOnesTurn();
}

void CCustomers::WaitOnesTurn()
{
	std::cout << "Customer No: " + std::to_string(number) + " is sleeping now\n";
	WaitForSingleObject(wakeupEvent, INFINITE);
	SetEvent(exitEvent);
}

HANDLE CCustomers::GetExitEvent()
{
	return exitEvent;
}

CCustomers::~CCustomers()
{
	CloseHandle(wakeupEvent);
	CloseHandle(exitEvent);
}