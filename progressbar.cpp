#include "progressbar.h"
#include <algorithm>

void ProgressBar::setProgress(float value)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_Progress = value;
}

void ProgressBar::setBarWidth(size_t width)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_BarWidth = width;
}

void ProgressBar::fillBarProgressWith(const std::string& chars)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_Fill = chars;
}

void ProgressBar::fillBarRemainderWith(const std::string& chars)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_RemainDer = chars;
}

void ProgressBar::setStatusText(const std::string& status)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_StatusText = status;
}

void ProgressBar::update(float value, std::ostream& os)
{
	setProgress(value);
	writeProgress(os);
}

void ProgressBar::writeProgress(std::ostream& os)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	if (m_Progress > 100.0f)
	{
		//on need to write once progress is 100%
		return;
	}

	// Move cursor to the first position on the same line and flush
	os << "\r" << std::flush;

	//start bar
	os << "[";

	const auto complted = static_cast<size_t>(m_Progress * static_cast<float>(m_BarWidth) / 100.0);
	for (size_t i = 0; i < m_BarWidth; ++i)
	{
		if (i <= complted)
		{
			os << m_Fill;
		}
		else
		{
			os << m_RemainDer;
		}
	}

	//end bar
	os << "]";

	//write progress percentage
	os << " " << std::min(static_cast<size_t>(m_Progress), size_t(100)) << "%";

	// write status text
	os << " " << m_StatusText;
}
