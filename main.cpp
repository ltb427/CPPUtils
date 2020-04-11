#include "threadpool.h"
#include <iostream>

using namespace std;

int val = 0;

int main()
{
	ThreadPool* pool = new ThreadPool(5, 10);
	for (int i = 0; i < 100; i++)
	{
		std::cout << "Push" << std::endl;
		pool->pushTask([&](const char* msg)
		{
			if (i == 10)
			{
				std::this_thread::sleep_for(std::chrono::seconds(3));
				std::cout <<" Is A Boy------------------------------------------------------" << std::endl;
			}
			/*if (i == 50)
			{
				pool->stop();
			}*/
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
				std::cout << msg << std::endl;
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}, "YuKai");
	}
	/*while (1);*/
	delete pool;
	return 0;
}