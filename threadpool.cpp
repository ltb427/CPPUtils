#include "threadpool.h"
#include <iostream>

ThreadPool::ThreadPool(const ThreadPoolSize size)
	:m_Stop(false), m_Size(size), m_HaveNew(false)
{
	//init work thread
	for (size_t i = 0; i < size; i++)
	{
		m_WorkThreds.push_back(std::thread([this]()
		{
			while (1)
			{
				std::unique_lock<std::mutex> lock(m_WorkMutex);
				m_WorkCv.wait(lock, [this]()->bool
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
				task();
			}
		}));
	}
	//init Admin thread
	m_Admin = std::thread([this]() 
	{
		while (1)
		{
			std::unique_lock<std::mutex> lock(m_WorkMutex);
			m_AdminCv.wait(lock, [this]()->bool
			{
				return m_HaveNew || m_Stop;
			});
			m_HaveNew = false;
			if (m_Stop)
			{
				return;
			}
			//std::unique_lock<std::mutex> lock1(m_WorkMutex);
			m_TaskQueues.emplace(m_Task);
			m_WorkCv.notify_one();
		}
	});
}

ThreadPool::~ThreadPool()
{
	std::cout << "Stop" << std::endl;
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_Stop = true;
	m_WorkCv.notify_all();
	m_AdminCv.notify_one();
}

void ThreadPool::pushTask(std::function<void()> task)
{
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_HaveNew = true;
	m_Task = task;
	m_AdminCv.notify_one();
}

void ThreadPool::stop()
{
	std::unique_lock<std::mutex> lock(m_WorkMutex);
	m_Stop = true;
	m_WorkCv.notify_all();
	m_AdminCv.notify_one();
}

void ThreadPool::start()
{
	for (auto& work : m_WorkThreds)
	{
		work.detach();
	}
	m_Admin.detach();
}
