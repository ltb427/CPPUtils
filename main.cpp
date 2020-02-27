#include <iostream>
#include <thread>
#include <mutex>


int hello_thread(int a, int b)
{
	int c = a + b;
	std::cout << a << "+" << b << "=" << c << std::endl;
	return c;
}

int main()
{
	std::thread th(hello_thread, 1, 2);
	th.join();
	std::cout << "Main Thread" << std::endl;
	return 0;
}

