#include "immutable_string.h"
#include <iostream>
#include<stdlib.h>
#include <time.h>

int main()
{
	time_t t;
	t = time(NULL);

	int ii = time(&t);
	for(int i= 0; i < 100000; ++i)
	{
		yukai::ImmutableString str("yukai");
		std::cout << str.getStr() << std::endl;
	}
	//time_t t1;
	//t1 = time(NULL);

	int ii1 = time(&t);
	std::cout << ii1 - ii << std::endl;
	return 0;
}