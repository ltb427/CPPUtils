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
	int a = 1;
	int b = 2;
	int& c = a;
	int& d = b;
	cout << sum<int>(std::move(a), std::move(b))<< endl;
	cout << sum<int>(a, b) << endl;
	cout << sum<int>(1, b) << endl;
	cout << sum<int>(1, 2) << endl;
	return 0;
}