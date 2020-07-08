#ifndef __SINGLEINSTANCE_HPP__
#define __SINGLEINSTANCE_HPP__

#include <mutex>
#include <atomic>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
问题1：必须加这个，否则以下编译不过
	cout << sum<int>(std::move(a), std::move(b))<< endl;
	cout << sum<int>(1, b) << endl;
	cout << sum<int>(1, 2) << endl;
*/
//template<typename T1, typename T2>
//auto sum(T1&& t1, T2&& t2) ->decltype(t1 + t2)
//{
//	return t1 + t2;
//}

/*
问题2：必须加这个，否则以下编译不过
	cout << sum<int>(a, b) << endl;
*/
//template<typename T1, typename T2>
//auto sum(T1& t1, T2& t2) ->decltype(t1 + t2)
//{
//	return t1 + t2;
//}

//完美的解决了问题1 和 问题2
template<typename T1, typename T2>
auto sum(T1 t1, T2 t2) ->decltype(t1 + t2)
{
	return std::forward<T1>(t1) + std::forward<T2>(t2);
}

struct Person
{
	string name;
	int age;
	string city;
};

/*
version 2: 使用result_of,按照city，age进行分组。
*/

typedef typename vector<Person>::value_type value_type;

template<typename Fn>
multimap<typename result_of<Fn(value_type)>::type, value_type> GroupBy(const vector<Person>& v, const Fn& f)
{
	typedef typename result_of<Fn(value_type)>::type ketype;
	//typedef  decltype(declval<Fn>()(declval <value_type>())) ketype;
	multimap<ketype, value_type> mymap;
	std::for_each(begin(v), end(v), [&mymap, &f](value_type item)
		{
			mymap.insert(make_pair(f(item), item));
		});
	return mymap;
}

//result_of的使用方法 留个坑，这个如何调用？
template< class Obj >
class CalculusVer2 {
public:
	template<class Arg>
	typename std::result_of<Obj(Arg)>::type operator()(Arg& a) const
	{
		return member(a);
	}
private:
	Obj member;
};

class A
{
public:
	int operator()(const int& a)
	{
		cout << a << endl;
		return a;
	}
};

template <typename T>
class SingleInstance
{
public:

	template<typename... Args>
	static T& Instance(Args... args)
	{
		T* tmp = m_pInstance.load(std::memory_order_acquire);
		if (tmp == nullptr)
		{
			std::lock_guard<std::mutex> lock(m_Mutex);
			tmp = m_pInstance.load(std::memory_order_relaxed);
			if (tmp == nullptr)
			{
				tmp = new T(std::forward<Args>(args)...);
				m_pInstance.store(tmp, std::memory_order_release);
			}
		}
		return *tmp;
	}

protected:

	SingleInstance()
	{
		auto buildCG = &m_Garbo;
	}

	virtual ~SingleInstance()
	{
		std::cout << "Delete Instance" << std::endl;
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
				delete tmp;
			}
		}
	};

private:

	SingleInstance(const SingleInstance& rhs) = delete;
	SingleInstance& operator = (const SingleInstance& rhs) = delete;
	SingleInstance& operator = (const SingleInstance&& rhs) = delete;

	static CGarbo						m_Garbo;
	static std::mutex					m_Mutex;
	static std::atomic<T*> volatile		m_pInstance;
};

template <typename T>
std::atomic<T*> volatile SingleInstance<T>::m_pInstance{ nullptr };

template<typename T>
std::mutex SingleInstance<T>::m_Mutex{};

template<typename T>
typename SingleInstance<T>::CGarbo SingleInstance<T>::m_Garbo{};


#endif // !__SINGLEINSTANCE_H__