#include "threadpool.h"
#include <iostream>

using namespace std;


int main()
{
	ThreadPool* pool = new ThreadPool(10);
	pool->start();
	for (int i = 0; i < 1000; i++)
	{
		std::cout << "Push" << std::endl;
		pool->pushTask([i]()
		{
			std::cout << "hello world " << i <<std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 10));
		});
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	while (1);
	return 0;
}