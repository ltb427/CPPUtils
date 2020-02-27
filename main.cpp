#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

class HelloThread 
{
public:
	void hellothread()
	{
		std::cout << "Hello World, I'm A Thread" << std::endl;
	}
	static void start()
	{
		std::thread th(std::bind(&HelloThread::hellothread, &HelloThread::getInsttance()));
		th.join();
	}
	static HelloThread& getInsttance()
	{
		if (instance == nullptr)
		{
			instance = new HelloThread;
		}
		return *instance;
	}
private:
	HelloThread() = default;
	static HelloThread* instance;
};

//类的静态成员初始化
HelloThread* HelloThread::instance = nullptr;

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

