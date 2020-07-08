#include <iostream>
#include "async.hpp"

int main()
{
	/*std::future<bool> fut = std::async(std::launch::async, []()->bool
		{
			std::this_thread::sleep_for(std::chrono::seconds(60));
			return true;
		});
	std::cout << "please wait";
	std::chrono::seconds span(1);
	while (fut.wait_for(span) != std::future_status::ready)
		std::cout << ".";
	std::cout << std::endl;

	bool ret = fut.get();
	std::cout << "final result: " << ret << std::endl;
	return 0;*/
	std::promise<int> prom;                      // create promise

	std::future<int> fut = prom.get_future();    // engagement with future

	std::thread th1([](std::future<int>& fut)
		{
			int x = fut.get();
			std::cout << "value: " << x << '\n';
		}, std::ref(fut));  // send future to new thread
	std::this_thread::sleep_for(std::chrono::seconds(5));
	prom.set_value(10);                         // fulfill promise
												 // (synchronizes with getting the future)
	th1.join();
	return 0;
}