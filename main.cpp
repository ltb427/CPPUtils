#include "threadpool.h"
#include <iostream>

using namespace std;

int val = 0;

int main()
{
	ThreadPool* pool = new ThreadPool(5, 5);
	pool->start();
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Push" << std::endl;
		pool->pushTask([i]()
		{
			if (i == 10)
			{
				std::this_thread::sleep_for(std::chrono::seconds(10));
				std::cout << "---------hello world---------- " << std::endl;
			}
			else if (i == 11)
			{
				std::this_thread::sleep_for(std::chrono::seconds(50));
				std::cout << "---------hello worldhhhhhhhhhh********** " << std::endl;
			}
			else if (i == 12)
			{
				std::this_thread::sleep_for(std::chrono::seconds(50));
				std::cout << "---------hello 111_________ " << std::endl;
			}
			else if (i == 13)
			{
				std::this_thread::sleep_for(std::chrono::seconds(50));
				std::cout << "---------hello 222+++++++++ " << std::endl;
			}
			else if (i == 14)
			{
				std::this_thread::sleep_for(std::chrono::seconds(50));
				std::cout << "---------hello 333}}}}}}}}} " << std::endl;
			}
			else
			{
				std::cout << "hello world " << i << std::endl;
			}
			
		});
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	while (1);
	delete pool;
	return 0;
}