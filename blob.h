#pragma once
#include <vector>
#include <memory>
#include <string>
#include <stdexcept>

template<typename T>
class Blob
{
public:
	typedef T value_type;
	//typdef 在模板中的使用方法
	typedef typename std::vector<T>::size_type size_type;
	Blob();
	//初始化类别的模板参数使用方法
	Blob(std::initializer_list<T> il);
	size_type size() const;
	bool empty() const;
	//添加和删除元素
	void push_back(const T& t);
	//移动版本
	void push_back(T&& t);
	void pop_back();
	//元素访问
	T& back();
	T& operator[](size_type i);
private:
	std::shared_ptr<std::vector<T>> data;
	//若data[i]无效，则抛出msg
	void check(size_type i, const std::string& msg) const;
};

template<typename T>
inline Blob<T>::Blob(std::initializer_list<T> il)
	: data(std::make_shared<std::vector<T>>(il))
{
}

template<typename T>
inline Blob<T>::Blob()
	: data(std::make_shared<std::vector<T>>())
{
}

template<typename T>
inline void Blob<T>::check(size_type i, const std::string& msg) const
{
	if (i >= data->size())
	{
		throw std::out_of_range(msg);
	}
}

template<typename T>
inline bool Blob<T>::empty() const
{
	return data->empty();
}

template<typename T>
inline void Blob<T>::push_back(const T& t)
{
	data->push_back(t);
}

template<typename T>
inline void Blob<T>::push_back(T&& t)
{
	data->push_back(std::move(t));
}

template<typename T>
inline void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
inline T& Blob<T>::back()
{
	// TODO: 在此处插入 return 语句
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
inline T& Blob<T>::operator[](size_type i)
{
	// TODO: 在此处插入 return 语句
	check(i, "back on empty Blob");
	return (*data)[i];
}

