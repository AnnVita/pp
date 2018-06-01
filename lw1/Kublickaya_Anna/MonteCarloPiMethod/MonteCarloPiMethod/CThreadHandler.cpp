#include "stdafx.h"
#include "CThreadHandler.h"

CThreadHandler::CThreadHandler()
{}

void CThreadHandler::AddThread(Thread const & thread)
{
	m_threads.push_back(thread);
}

void CThreadHandler::Execute()
{
	WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
}

CThreadHandler::~CThreadHandler()
{
	for (auto & thread : m_threads)
	{
		CloseHandle(thread);
	}
}