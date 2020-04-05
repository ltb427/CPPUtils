#include <thread>
#include <functional>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>


class ThreadPool
{
	public:
		using ThreadPoolSize = std::vector<std::thread>::size_type;
		ThreadPool(const ThreadPoolSize size);
		~ThreadPool();
		void pushTask(std::function<void()> task);
		void stop();
		void start();
		int getTaskSize()
		{
			return m_TaskQueues.size();
		}
	private:
		std::thread							m_Admin;
		std::queue<std::function<void()>>	m_TaskQueues;
		std::vector<std::thread>			m_WorkThreds;
		std::mutex							m_WorkMutex;
		bool								m_Stop;
		ThreadPoolSize						m_Size;
		std::function<void()>				m_Task;
};