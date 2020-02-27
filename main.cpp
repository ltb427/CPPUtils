#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

static std::mutex mt;
static int data = 1;

void add(int a)
{
	while (1)
	{
		mt.lock();
		data += a;
		std::cout << "add data= " << data << std::endl;
		mt.unlock();
	}
}

void cut(int a)
{
	while (1)
	{
		mt.lock();
		data -= a;
		std::cout << "cut data= " << data << std::endl;
		mt.unlock();
	}
}

int main(int argc, char* argv[])
{
	std::thread th1(add, 2);
	std::thread th2(cut, 1);
	th1.join();
	th2.join();
	return 0;
}

