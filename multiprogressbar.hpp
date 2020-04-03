#pragma once
#include <atomic>
#include <mutex>
#include <functional>
#include <iostream>
#include <array>

template <typename Indicator, size_t count>
class MultiProgressBar
{
public:
	template <typename... Indicators, typename = typename std::enable_if_t<(sizeof...(Indicators) == count)>>
	explicit MultiProgressBar(Indicators & ...bars)
		: m_Bars({ bars... })
	{

	}
	template <size_t index>
	typename std::enable_if_t<(index >= 0 && index < count), void>
		update(float value, std::ostream& os = std::cout)
	{
		m_Bars[index].get().setProgress(value);
		writeProgress(os);
	}
private:
	std::array<std::reference_wrapper<Indicator>, count> m_Bars;
	void writeProgress(std::ostream& os = std::cout) 
	{
		std::unique_lock<std::mutex> lock(m_Mutex);
		//system("cls");
		
		// Move cursor up if needed
		/*if (m_Started)
		{
			for (size_t i = 0; i < count; ++i)
			{
				os << "\\x1b[A";
			}
		}*/

		// Write each bar
		for (auto& bar : m_Bars) 
		{
			bar.get().writeProgress();
			os << std::endl;
		}

		if (!m_Started)
		{
			m_Started = true;
		}
	}
	std::mutex m_Mutex;
	std::atomic<bool> m_Started{ false };
};
