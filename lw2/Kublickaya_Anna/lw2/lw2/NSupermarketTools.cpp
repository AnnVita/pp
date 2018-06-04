#include "stdafx.h"
#include "NSupermarketTools.h"

namespace NSupermarketTools
{
	DWORD WINAPI HandleCashier(LPVOID parameter)
	{
		Cashier *cashier = reinterpret_cast<Cashier*>(parameter);
		cashier->ServeCustomers();
		return 0;
	}

	DWORD WINAPI HandleCustomer(LPVOID parameter)
	{
		CustomersInfo* data = reinterpret_cast<CustomersInfo*>(parameter);
		Customer* customer = data->customer;
		customer->Action(data->cashiers);
		return 0;
	}
}