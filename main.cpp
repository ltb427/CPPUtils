#include<iostream>
#include<thread>
#include "sem.h"

using namespace std;

//int						 g_semValue = -1;
//std::mutex 				 g_mutex;
//std::condition_variable  g_cv;
Sem sem(0);

void thread_fun(void);

int main()
{
	thread th1(thread_fun);
	/*unique_lock<mutex> lk(g_mutex);
	g_semValue = 2;
	if (!g_cv.wait_for(lk, chrono::seconds(5), [=]()->bool {return g_semValue == -1; }))
	{
		cout << "TimeOut" << endl;
	}
	else
	{
		cout << "Ok" << endl;
	}*/
	if (!sem.wait(std::chrono::seconds(5)))
	{
		cout << "TimeOut" << endl;
	}
	else
	{
		cout << "Ok" << endl;
	}
	th1.detach();
	return 0;
}

void thread_fun(void)
{
	this_thread::sleep_for(chrono::seconds(20));
	sem.notify();
}