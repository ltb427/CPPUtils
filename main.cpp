#include "threadpool.h"
#include <iostream>
#include "async.hpp"

using namespace std;

int main()
{
	AsyncTask<int> task(([](int i)->int
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(i));
			return 0;
		}), 2500);
	int i = task.Execute();
	cout << "result is " << i << endl;
	return 0;
}