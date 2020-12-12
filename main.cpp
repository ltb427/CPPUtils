#include <iostream>

//使用函数指针
typedef int(*pfc)(int,int);

int add(int x, int y)
{
	return x+y;
}

int call_fn(pfc ptr, int x, int y)
{
	return ptr(x,y);
}

int main()
{
	std::cout << call_fn(add, 1, 2) << std::endl;
	return 0;
}