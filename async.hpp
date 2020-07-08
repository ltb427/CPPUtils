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
