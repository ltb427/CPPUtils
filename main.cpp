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
	vector<Person> v = { {"aa", 20, "shanghai"}, { "bb", 25, "beijing" }, { "cc", 25, "nanjing" }, { "dd", 20, "nanjing" } };
	// group by age
	auto r1 = GroupBy(v, [](const Person& person) {return person.age; });
	// group by name
	auto r2 = GroupBy(v, [](const Person& person) {return person.name; });
	// group by city
	auto r3 = GroupBy(v, [](const Person& person) {return person.city; });
	//遍历multimap 方法1 键值查找
	auto pr = r1.equal_range(20);
	if (pr.first != std::end(r1))
	{
		for (auto iter = pr.first; iter != pr.second; ++iter)
			std:cout << iter->first << " is " << iter->second.name << std::endl;
	}
	//遍历multimap 方法1 条件查找 大于20
	auto pr1 = r1.upper_bound(20);
	while (pr1 != std::end(r1))
	{
		cout << pr1->second.name << endl;
		++pr1;
	}
	return 0;
}