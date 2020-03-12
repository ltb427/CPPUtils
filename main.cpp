#include<iostream>
#include<thread>
#include "sem.h"

using namespace std;

//int						 g_semValue = -1;
//std::mutex 				 g_mutex;
//std::condition_variable  g_cv;
Sem sem(0);

void thread_fun(void);
void thread_fun1(void);

int main()
{
	thread th1(thread_fun), th2(thread_fun1);
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
	sem.wait();
	cout << "Ok" << endl;
	th1.detach();
	th2.detach();
	return 0;
}

void thread_fun(void)
{
	/*this_thread::sleep_for(chrono::seconds(10));
	unique_lock<mutex> lk(g_mutex);
	if (g_semValue != -1)
	{
		--g_semValue;
		if (g_semValue == 0)
		{
			g_semValue = -1;
			g_cv.notify_one();
		}
	}*/
	this_thread::sleep_for(chrono::seconds(10));
	sem.notify();
}

void thread_fun1(void)
{
	/*this_thread::sleep_for(chrono::seconds(1));
	unique_lock<mutex> lk(g_mutex);
	if (g_semValue != -1)
	{
		--g_semValue;
		if (g_semValue == 0)
		{
			g_semValue = -1;
			g_cv.notify_one();
		}
	}*/
}