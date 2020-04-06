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
	private:
		std::queue<std::function<void()>>	m_TaskQueues;
		std::vector<std::thread>			m_WorkThreds;
		std::mutex							m_WorkMutex;
		std::condition_variable				m_Cv;
		bool								m_Stop;
};