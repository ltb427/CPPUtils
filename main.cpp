#include <iostream>
#include <vector>

using namespace std;

//函数模板
template<typename T> inline //inline在模板中的使用方法
int compare(const T& left, const T& right)
{
	return left > right ? 1 : -1;
}

int main()
{
	//实例化模板
	cout << compare(1, 0) << endl;
	vector<int> vec1{ 9,2,3,4 }, vec2{ 4,5,6 };
	cout << compare(vec1, vec2) << endl;
	return 0;
}