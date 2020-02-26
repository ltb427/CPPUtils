#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

void thread_fun(void);

static int g_value = 0;
static std::condition_variable g_cv;
static std::mutex g_lk;

int main()
{
	std::thread th(thread_fun);
	std::unique_lock<std::mutex> lk(g_lk);
	if (g_cv.wait_for(lk,std::chrono::seconds(5)) == std::cv_status::timeout)
	{
		std::cout << "timeout" << std::endl;
	}
	else
	{
		std::cout << "You Entryed:" << g_value << std::endl;
	}
	th.detach();
	return 0;
}

void thread_fun(void)
{
	std::cin >> g_value;
	g_cv.notify_one();
}