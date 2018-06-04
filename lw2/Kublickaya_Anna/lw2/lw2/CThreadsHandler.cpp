#include "stdafx.h"
#include "CThreadHandler.h"

void ThreadsHandler::AddThread(LPTHREAD_START_ROUTINE threadProc, LPVOID param)
{
	threads.push_back(CreateThread(NULL, 0, threadProc, param, 0, 0));
}

void ThreadsHandler::WaitAll()
{
	WaitForMultipleObjects(DWORD(threads.size()), threads.data(), true, INFINITE);
}

void ThreadsHandler::CloseAll()
{
	for (size_t i = 0; i < threads.size(); i++)
	{
		TerminateThread(threads[i], 0);
	}
}

ThreadsHandler::~ThreadsHandler()
{
	for (auto &thread : threads)
	{
		CloseHandle(thread);
	}
}