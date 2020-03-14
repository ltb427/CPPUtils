#include "screen.h"

int main()
{
	yukai::Screen myScreen(5,3, '@');
	const yukai::Screen blank(5, 3, '%');
	myScreen.set('#').display(std::cout);
	std::cout << std::endl;
	blank.display(std::cout);
	std::cout << std::endl;
	std::cin >> myScreen;
	std::cout << myScreen;
	return 0;
}