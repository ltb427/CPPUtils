#include <iostream>
#include <vector>
#include <functional>
#include "blob.h"

using namespace std;


int main()
{
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