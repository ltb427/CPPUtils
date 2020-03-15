#include "screen.h"

using namespace yukai;

int main()
{
	//类的作用域访问using 或typedef定义的类型
	Screen::pos ht = 10;
	Window_mgr mgr;
	mgr.clear(0);
	Window_mgr::ScreenIndex index = mgr.addScreen(Screen(10 * 21, '#'));
	std::cout << index << std::endl;
	index = mgr.addScreen(Screen(10 * 21, '#'));
	std::cout << index << std::endl;
	return 0;
}