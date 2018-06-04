#pragma once
#include "stdafx.h"

class ThreadsHandler
{
public:
	void AddThread(LPTHREAD_START_ROUTINE threadProc, LPVOID param);
	void WaitAll();
	void CloseAll();
	~ThreadsHandler();
private:
	std::vector<HANDLE> threads;
};