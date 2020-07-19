#include "threadpool.h"
#include <iostream>
#include "async.hpp"

using namespace std;

int main()
{
	std::thread th1(thread_func1, MSG);
	std::thread th2(thread_func2, MSG);
	std::thread th3(thread_func3, MSG);
	std::thread th4(thread_func4, MSG);
	th1.join();
	th2.join();
	th3.join();
	th4.join();
	return 0;
}