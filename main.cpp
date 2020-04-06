#include "threadpool.h"
#include <iostream>

using namespace std;

int val = 0;

int main()
{
	ThreadPool* pool = new ThreadPool(5, 5);
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Push" << std::endl;
		pool->pushTask([&]()
		{
			if (i == 10)
			{
				std::this_thread::sleep_for(std::chrono::seconds(10));
				std::cout << "---------hello world---------- " << i << std::endl;
			}
			/*if (i == 50)
			{
				pool->stop();
			}*/
			else
			{
				std::cout << "hello world " << i << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		});
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	while (1);
	delete pool;
	return 0;
}