#include "threadpool.h"
#include <iostream>
#include "async.hpp"

using namespace std;

int main()
{
	std::future<int> fut = really_async([](int i)->int
	{
		std::this_thread::sleep_for(std::chrono::seconds(i));
		return i;
	}, 5);
	std::future_status status = fut.wait_for(std::chrono::seconds(10));
	if (status == std::future_status::ready)
	{
		cout << "ok" << endl;
		int i = fut.get();
		cout << "res is " << i << endl;
	}
	else
	{
		cout << "timeout" << endl;
	}
	return 0;
}