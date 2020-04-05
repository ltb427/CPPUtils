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
			std::cout << "hello world " << i <<std::endl;
			/*std::this_thread::sleep_for(std::chrono::seconds(1));*/
		});
		std::this_thread::sleep_for(std::chrono::milliseconds(5));
		/*if (i ==5 )
		{
			pool->stop();
		}*/
	}
	pool->pushTask([]() {
		std::cout << "Over" << endl;
	});
	return 0;
}