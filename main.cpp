#include <iostream>
#include "async.hpp"

int main()
{
	std::future<bool> fut = std::async(std::launch::async, []()->bool
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
	return 0;
}