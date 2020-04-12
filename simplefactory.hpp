#pragma once
#include <iostream>

using namespace std;

//定义产品类型信息
typedef enum
{
	Tank_Type_56,
	Tank_Type_96,
	Tank_Type_Num
}Tank_Type;

//抽象产品类
class Tank
{
public:
	virtual const string& type() = 0;
};

//具体的产品类
class Tank56 : public Tank
{
public:
	Tank56()
		:Tank(), m_strType("Tank56")
	{

	}
	const string& type() override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
private:
	string m_strType;
};

//具体的产品类
class Tank96 : public Tank
{
public:
	Tank96()
		:Tank(), m_strType("Tank96")
	{

	}
	const string& type() override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
private:
	string m_strType;
};

//工厂类
class TankFactory
{
public:
	//根据产品信息创建具体的产品实例，返回一个抽象类产品指针
	Tank* createTank(Tank_Type type)
	{
		switch (type)
		{
		case Tank_Type_56:
			return new Tank56();
		case Tank_Type_96:
			return new Tank96();
		default:
			return nullptr;
		}
	}
};