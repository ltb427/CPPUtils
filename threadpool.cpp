#include "threadpool.h"
#include <iostream>

ThreadPool::ThreadPool(const ThreadPoolSize size)
	:m_Stop(false), m_Size(size)
{
	//init work thread
	for (size_t i = 0; i < size; i++)
	{
		m_WorkThreds.push_back(std::thread([this]()
		{
			while (1)
			{
				/*std::unique_lock<std::mutex> lock(m_WorkMutex);*/
				m_WorkMutex.lock();
				if (m_TaskQueues.empty())
				{
					m_WorkMutex.unlock();
					continue;
				}
				if (m_Stop)
				{
					m_WorkMutex.unlock();
					return;
				}
				std::function<void()> task;
				task = std::move(this->m_TaskQueues.front());
				this->m_TaskQueues.pop();
				m_WorkMutex.unlock();
				task();
			}
		}));
	}
}

ThreadPool::~ThreadPool()
{
	m_WorkMutex.lock();
	m_Stop = true;
	m_WorkMutex.unlock();
}

void ThreadPool::pushTask(std::function<void()> task)
{
	m_WorkMutex.lock();
	m_TaskQueues.emplace(task);
	m_WorkMutex.unlock();
}

void ThreadPool::stop()
{
	m_WorkMutex.lock();
	m_Stop = true;
	m_WorkMutex.unlock();
}

void ThreadPool::start()
{
	for (auto& work : m_WorkThreds)
	{
		work.detach();
	}
}
