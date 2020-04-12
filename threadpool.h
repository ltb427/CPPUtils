#include <thread>
#include <functional>
#include <queue>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <future>


class ThreadPool
{
	public:
		using ThreadPoolSize = std::vector<std::thread>::size_type;
		using TaskQueueSize = std::queue<std::function<void()>>::size_type;
		ThreadPool(const ThreadPoolSize poolSize, const TaskQueueSize taskSize);
		~ThreadPool();
		//void pushTask(std::function<void()> task);
		void stop();
		template<class F, class... Args>
		void pushTask(F&& f, Args&& ... args);
	private:
		std::queue<std::function<void()>>	m_TaskQueues;
		std::vector<std::thread>			m_WorkThreds;
		std::mutex							m_WorkMutex;
		std::condition_variable				m_NullCv;
		std::condition_variable				m_FullCv;
		bool								m_Stop;
		TaskQueueSize						m_TaskSize;
};

// add new work item to the pool
template<class F, class... Args>
void ThreadPool::pushTask(F&& f, Args&& ... args)
{
	using return_type = typename std::result_of<F(Args...)>::type;

	auto task = std::make_shared< std::packaged_task<return_type()>>(
		std::bind(std::forward<F>(f), std::forward<Args>(args)...)
	);
	{
		std::unique_lock<std::mutex> lock(m_WorkMutex);
		m_FullCv.wait(lock, [this]()->bool
		{
			return m_TaskQueues.size() < m_TaskSize || m_Stop;
		});
		// don't allow enqueueing after stopping the pool
		if (m_Stop)
		{
			throw std::runtime_error("enqueue on stopped ThreadPool");
		}
		m_TaskQueues.emplace([task]() { (*task)(); });
	}
	m_NullCv.notify_one();
}