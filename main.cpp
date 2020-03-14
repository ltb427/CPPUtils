#include <iostream>
#include <vector>
#include <functional>

using namespace std;

//函数模板
template<typename T> inline //inline在模板中的使用方法
int compare(const T& left, const T& right)
{
	if (less<T>()(left, right)) return -1;
	if (less<T>()(right, left)) return 1;
	return 0;
}



int main()
{
	//实例化模板
	cout << compare(1, 0) << endl;
	vector<int> vec1{ 4,5,6,6 }, vec2{ 4,5,6,5 };
	cout << compare(vec1, vec2) << endl;
	return 0;
}