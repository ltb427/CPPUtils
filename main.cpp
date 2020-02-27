#include <iostream>
#include <thread>
#include <mutex>

class HelloThread 
{
public:
	static void hellothread()
	{
		std::cout << "Hello World, I'm A Thread" << std::endl;
	}
	static void start()
	{
		std::thread th(hellothread);
		th.join();
	}
};

int hello_thread(int a, int b)
{
	int c = a + b;
	std::cout << a << "+" << b << "=" << c << std::endl;
	return c;
}

int main()
{
	HelloThread::start();
	return 0;
}

