#ifndef __SINGLEINSTANCE_HPP__
#define __SINGLEINSTANCE_HPP__

#include <mutex>
#include <atomic>

template <typename T>
class SingleInstance
{
public:

	static T& Instance()
	{
		T* tmp = m_pInstance.load(std::memory_order_acquire);
		if (tmp == nullptr)
		{
			std::lock_guard<std::mutex> lock(m_Mutex);
			tmp = m_pInstance.load(std::memory_order_relaxed);
			if (tmp == nullptr)
			{
				tmp = new T();
				m_pInstance.store(tmp, std::memory_order_release);
			}
		}
		return *tmp;
	}

protected:

	SingleInstance()
	{
		/*auto buildCG __attribute__((unused)) = &m_Garbo;*/
	}

	virtual ~SingleInstance()
	{
		std::cout << "Delete" << std::endl;
	}

	class CGarbo
	{
	public:
		~CGarbo()
		{
			if (SingleInstance::m_pInstance)
			{
				T* tmp = SingleInstance::m_pInstance.load(std::memory_order_acquire);
				m_pInstance.store(nullptr, std::memory_order_release);
				std::cout << "Delete" << std::endl;
				delete tmp;
			}
		}
	};

private:

	SingleInstance(const SingleInstance& rhs) = delete;
	SingleInstance& operator = (const SingleInstance& rhs) = delete;
	SingleInstance& operator = (const SingleInstance&& rhs) = delete;

	static CGarbo m_Garbo;
	static std::mutex m_Mutex;
	static std::atomic<T*> volatile m_pInstance;
};

template <typename T>
std::atomic<T*> volatile SingleInstance<T>::m_pInstance{ nullptr };

template<typename T>
std::mutex SingleInstance<T>::m_Mutex{};

template<typename T>
typename SingleInstance<T>::CGarbo SingleInstance<T>::m_Garbo{};


#endif // !__SINGLEINSTANCE_H__

