#include <iostream>
#include <vector>
#include <functional>
#include "SingleInstance.hpp"
#include "blob.h"

using namespace std;


class Cat : public SingleInstance<Cat>
{
public:
	friend SingleInstance<Cat>;
	void say()
	{
		a += 1;
		cout << " cat say hello " << a << endl;
	}

private:
	Cat(const int v)
		: a(0)
	{
		cout << "This is me" << endl;
	}
	Cat()
	{
		cout << "SingleIntance::SingleInstanc" << endl;
		a = 0;
	}

	~Cat()
	{
		cout << "Delete Cat" << endl;
	}

	Cat(const Cat& rhs)
	{
		cout << "SingleInstance::SingleInstance(const SingleIntance& rhs)" << endl;
	}
	int a;
};


int main()
{
	Cat& cat = Cat::Instance(5);
	cat.say();
	Cat& cat1 = Cat::Instance(100);
	cat1.say();
	Blob<int> ia;
	Blob<int> ia2 = {0, 1, 2, 3, 4};
	ia.push_back(3);
	int a = ia2.back();
	cout << a << endl;
	bool flag = ia.empty();
	cout << flag << endl;
	ia.pop_back();
	a = ia2[3];
	cout << a << endl;
	return 0;
}