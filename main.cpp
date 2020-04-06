#include "threadpool.h"
#include <iostream>

using namespace std;

int val = 0;

int main()
{
	ThreadPool* pool = new ThreadPool(10);
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
			if (i == 11)
			{
				std::this_thread::sleep_for(std::chrono::seconds(10));
				std::cout << "---------hello worldhhhhhhhhhh---------- " << std::endl;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::seconds(rand() % 5));
				std::cout << "hello world " << i << std::endl;
			}
			
		});
		std::this_thread::sleep_for(std::chrono::seconds(2));
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	while (1);
	delete pool;
	return 0;
}