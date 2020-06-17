#ifndef __ASYNC_H__
#define __ASYNC_H__
#include <future>
#include <mutex>

using namespace std;

static std::mutex m_mutex;

template<class T>
class AsyncTask
{
public:
	template<class F, class ...Args>
	AsyncTask(F&& f, Args&& ... args)
		:m_future(std::async(std::bind(std::forward<F>(f), std::forward<Args>(args)...)))
	{

	}
	T Execute()
	{
		std::unique_lock<std::mutex> lck(m_mutex);
		return m_future.get();
	}
	virtual ~AsyncTask() = default;
private:
	std::future<T> m_future;
};


#endif // !__ASYNC_H__

