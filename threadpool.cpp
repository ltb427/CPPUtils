#include "threadpool.h"
#include <iostream>

ThreadPool::ThreadPool(const ThreadPoolSize size)
	:m_Stop(false)
{
	//init work thread
	for (size_t i = 0; i < size; i++)
	{
		m_WorkThreds.push_back(std::thread([this]()
		{
			while (1)
			{
				std::unique_lock<std::mutex> lock(m_WorkMutex);
				m_Cv.wait(lock, [this]()->bool 
				{
					return !m_TaskQueues.empty() || m_Stop;
				});
				if (m_Stop)
				{
					return;
				}
				std::function<void()> task;
				task = std::move(this->m_TaskQueues.front());
				this->m_TaskQueues.pop();
				lock.unlock();
				task();
			}
		}));
	}
}

ThreadPool::~ThreadPool()
{
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_Stop = true;
}

void ThreadPool::pushTask(std::function<void()> task)
{
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_TaskQueues.emplace(task);
	m_Cv.notify_one();
}

void ThreadPool::stop()
{
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_Stop = true;
}

void ThreadPool::start()
{
	for (auto& work : m_WorkThreds)
	{
		work.detach();
	}
}
