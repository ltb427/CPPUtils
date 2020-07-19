#ifndef __ASYNC_H__
#define __ASYNC_H__
#include <future>
#include <mutex>
#include <functional>
#include <thread>

using namespace std;

static std::mutex m_mutex;

template <typename F, typename... Args>
auto really_async(F&& f, Args&& ... args)-> std::future<typename std::result_of<F(Args...)>::type>
{
	using _Ret = typename std::result_of<F(Args...)>::type;
	auto _func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);
	std::packaged_task<_Ret()> tsk(std::move(_func));
	auto _fut = tsk.get_future();
	std::thread thd(std::move(tsk));
	thd.detach();
	return _fut;
}

#define MSG	"Hello,std::call_once"

void printTask(const char* msg)
{
	std::cout << msg << endl;
}

void task(const char* msg)
{
	static std::once_flag flag;//std::once_flag必须是全局变量或者静态变量
	std::call_once(flag, printTask, msg);
}

void thread_func1(const char* msg)
{
	task(msg);
}

void thread_func2(const char* msg)
{
	task(msg);
}

void thread_func3(const char* msg)
{
	task(msg);
}

void thread_func4(const char* msg)
{
	task(msg);
}

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

