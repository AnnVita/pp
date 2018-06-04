#include "stdafx.h"

using namespace std;
using namespace NSupermarketTools;
const size_t NEEDFUL_ARGUMENTS_COUNT = 2;

int main(int argc, char* argv[])
{
	if (argc != NEEDFUL_ARGUMENTS_COUNT)
	{
		std::cout << "Invalid argumets count! \n Use: Supermarket.exe <number of customers>" << endl;
		return 1;
	}

	size_t customersCount = stoi(argv[1]);
	ThreadsHandler handler;
	srand(time(NULL));
	vector<CCashier*> cashiers = { new CCashier(1), new CCashier(2) };
	for (auto cashier : cashiers)
	{
		handler.AddThread(HandleCashier, cashier);
	}
	vector<CCustomers*> customers;
	vector<CustomersInfo*> customersData;
	for (size_t i = 0; i < customersCount; i++)
	{
		customers.push_back(new CCustomers(i));
		customersData.push_back(new CustomersInfo{ cashiers, customers.back() });
		handler.AddThread(HandleCustomer, customersData.back());
	}
	handler.WaitAll();
	return 0;
}