
#include "progressbar.h"
#include <thread>
#include "termcolor.hpp"
#include "multiprogressbar.hpp"

int main()
{
	std::cout << termcolor::bold << termcolor::yellow;

	ProgressBar bar1, bar2, bar3;
	bar1.fillBarProgressWith("■");
	bar1.fillBarRemainderWith("-");
	bar1.setStatusText("work 1");
	bar2.fillBarProgressWith("■");
	bar2.fillBarRemainderWith("-");
	bar2.setStatusText("work 2");
	bar3.fillBarProgressWith("■");
	bar3.fillBarRemainderWith("-");
	bar3.setStatusText("work 3");
	MultiProgressBar<ProgressBar, 3> bars(bar1, bar2, bar3);

	// Job for the first bar
	auto job1 = [&bars]() 
	{
		for (size_t i = 0; i <= 101; ++i) 
		{
			bars.update<0>(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	};

	// Job for the second bar
	auto job2 = [&bars]() 
	{

		for (size_t i = 0; i <= 101; ++i) 
		{
			bars.update<1>(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(200));
		}
	};

	// Job for the third bar
	auto job3 = [&bars]() 
	{
		for (size_t i = 0; i <= 101; ++i) 
		{
			bars.update<2>(i);
			std::this_thread::sleep_for(std::chrono::milliseconds(60));
		}
	};

	std::thread first_job(job1);
	std::thread second_job(job2);
	std::thread third_job(job3);

	first_job.join();
	second_job.join();
	third_job.join();

	std::cout << termcolor::reset << std::endl;

	return 0;
}