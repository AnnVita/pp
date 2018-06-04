#pragma once
#include "stdafx.h"

namespace NSupermarketTools
{
	struct CustomersInfo
	{
		std::vector<Cashier*> cashiers;
		Customer* customer;
	};
	DWORD WINAPI HandleCashier(LPVOID parameter);
	DWORD WINAPI HandleCustomer(LPVOID parameter);
}