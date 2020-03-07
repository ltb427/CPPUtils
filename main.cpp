#include "screen.h"

int main()
{
	screen_display::Screen myScreen(5,3, '@');
	const screen_display::Screen blank(5, 3, '%');
	myScreen.set('#').display(std::cout);
	std::cout << std::endl;
	blank.display(std::cout);
	std::cout << std::endl;
	return 0;
}