#include "threadpool.h"
#include <iostream>

using namespace std;


int main()
{
	ThreadPool* pool = new ThreadPool(10);
	pool->start();
	for (int i = 0; i < 10; i++)
	{
		pool->pushTask([i]()
		{
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 9));
			std::cout << "hello world " << i <<std::endl;
		});
		//std::this_thread::sleep_for(std::chrono::milliseconds(2));
		/*if (i ==5 )
		{
			pool->stop();
		}*/
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	//while (1);
	return 0;
}