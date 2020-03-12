#include "sem.h"

Sem::Sem()
	:m_SemValue(0)
{

}

Sem::~Sem()
{
	
}

Sem::Sem(const int& semValue)
	:m_SemValue(semValue)
{
}

void Sem::wait()
{
	std::unique_lock<std::mutex>lock(m_Mutex);
	m_SemValue += 1;
	return m_Cv.wait(lock, [=]()->bool {return m_SemValue == 0; });
}

void Sem::wait(const int& semValue)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_SemValue = semValue;
	return m_Cv.wait(lock, [=]()->bool {return m_SemValue == 0; });
}

void Sem::notify()
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	m_SemValue -= 1;
	if (m_SemValue == 0)
	{
		m_Cv.notify_one();
	}
}


