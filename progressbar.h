#pragma once

#include <atomic>
#include <mutex>
#include <iostream>

class ProgressBar
{
public:
	void setProgress(float value);
	void setBarWidth(size_t width);
	void fillBarProgressWith(const std::string& chars);
	void fillBarRemainderWith(const std::string& chars);
	void setStatusText(const std::string& status);
	void update(float value, std::ostream& os = std::cout);
	void writeProgress(std::ostream& os = std::cout);
private:
	std::mutex m_Mutex;
	float m_Progress{ 0.0f };
	size_t m_BarWidth{ 100 };
	std::string m_Fill{ "#" };
	std::string m_RemainDer{ " " };
	std::string m_StatusText{ " " };
};

