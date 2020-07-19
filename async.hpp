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

/*
用const替代#define
当程序中需要定义一些常量的时候，用const比用#define要好：
因为#define是属于预处理器的语法，只是简单地进行宏替换，
而const是C++编译器的语法，能提供类型检查以及调试信息。
用constexpr替代const
C++11引入constexpr来区分出编译期常量。由于很多场景需要的
不仅仅是常量，而是编译时期就能知道值的常量，比如数据的大
小，模板类的整型参数，设置alignment内存对齐，switch中的标
签等等。
const没有从语义上区分出是否为编译期常量，这样可能就会造成
编译器会为编译期常量开辟全局存储空间，并且不允许类内初始化
静态非整型变量：
如下：
class Foo {
public :
	static const double PI = 3.14;        //不允许类内初始化静态非整型变量
	static constexpr double PI = 3.14;    //OK
};
*/
constexpr auto MSG = "Hello,std::call_once";

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

