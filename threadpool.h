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
		using TaskQueueSize = std::queue<std::function<void()>>::size_type;
		ThreadPool(const ThreadPoolSize poolSize, const TaskQueueSize taskSize);
		~ThreadPool();
		void pushTask(std::function<void()> task);
		void stop();
	private:
		std::queue<std::function<void()>>	m_TaskQueues;
		std::vector<std::thread>			m_WorkThreds;
		std::mutex							m_WorkMutex;
		std::condition_variable				m_NullCv;
		std::condition_variable				m_FullCv;
		bool								m_Stop;
		TaskQueueSize						m_TaskSize;
};