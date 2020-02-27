#include <iostream>
#include <thread>
#include <mutex>


void hello_thread()
{
	std::cout << "HelloThread" << std::endl;
}

int main()
{
	std::thread th(hello_thread);
	th.join();
	std::cout << "Main Thread" << std::endl;
	return 0;
}

