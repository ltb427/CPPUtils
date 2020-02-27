#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

class HelloThread
{
public:
	void hello(int year)
	{
		std::cout << "I am " << year << " old" << std::endl;
	}
};

int main(int argc, char* argv[])
{
	HelloThread obj;
	std::thread th(std::bind(&HelloThread::hello, &obj, 26));
	th.join();
	return 0;
}

