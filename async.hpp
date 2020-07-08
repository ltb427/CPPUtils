#pragma once
#include <future>
#include <iostream>
#include <thread>
#include <functional>

bool is_prime(int x)
{
	for (int i = 0; i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

/*
std::promise的作用就是提供一个不同线程之间的数据同步机制，它可以存储一个某种类型的值，
并将其传递给对应的future， 即使这个future不在同一个线程中也可以安全的访问到这个值。

std::packaged_task的作用就是提供一个不同线程之间的数据同步机制，它可以存储一个函数操作，
并将其返回值传递给对应的future， 而这个future在另外一个线程中也可以安全的访问到这个值。
*/