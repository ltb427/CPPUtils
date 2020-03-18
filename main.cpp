
#include "progressbar.h"
#include <thread>
#include "termcolor.hpp"

int main()
{
	std::cout << termcolor::bold << termcolor::yellow;
	ProgressBar bar;
	bar.setBarWidth(50);
	bar.fillBarProgressWith("■");
	bar.fillBarRemainderWith("-");

	for (size_t i = 0; i <= 100; ++i)
	{
		bar.update(i);
		if (i == 99)
		{
			bar.setStatusText("complted");
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}
	std::cout << termcolor::reset;
	return 0;
}