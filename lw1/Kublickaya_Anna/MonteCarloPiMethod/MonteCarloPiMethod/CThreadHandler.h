#pragma once

using Thread = HANDLE;
using Threads = std::vector<Thread>;

class CThreadHandler
{
public:
	CThreadHandler();
	~CThreadHandler();
	void AddThread(Thread const& thread);
	void Execute();
private:
	Threads m_threads;
};