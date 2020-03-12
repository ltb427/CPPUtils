#ifndef __SEM_H__
#define __SEM_H__

//#include<thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

class Sem
{
public:
	Sem();
	~Sem();
	Sem(const int& semValue);
	//普通的等待异步消息, wait会进行m_SemValue+=1操作
	void wait();
	//等待semValue个异步消息，才能唤醒，wait不会进行m_SemValue+=1操作
	//但会对m_SemValue进行赋值
	void wait(const int& semValue);
	//等待一定时间的异步消息,wait会进行m_SemValue+=1操作
	template <class _Rep, class _Period>
	bool wait(const std::chrono::duration<_Rep, _Period>& _Rel_time);
	//唤醒 会进行m_SemValue-=1操作
	void notify();

private:
	int m_SemValue;
	std::condition_variable  m_Cv;
	std::mutex m_Mutex;
};

template<class _Rep, class _Period>
inline bool Sem::wait(const std::chrono::duration<_Rep, _Period>& _Rel_time)
{
	std::unique_lock<std::mutex> lock(m_Mutex);
	++m_SemValue;
	return m_Cv.wait_for(lock, _Rel_time, [=]()->bool {return m_SemValue == 0; });
}

#endif // !__SEM_H__


