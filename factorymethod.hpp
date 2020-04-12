#pragma once
#include <iostream>

using namespace std;

//产品抽象类
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
		: Tank(), m_strType("Tank56")
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
		: Tank(), m_strType("Tank96")
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

//抽象工厂，提供一个创建接口
class TankFactory
{
public:
	//提供一个创建具体产品实例的接口，返回抽象产品类
	virtual Tank* createTank() = 0;
};

//具体的创建工厂类，使用抽象工厂提供的接口，去创建具体的产品实例
class Tank56Factory : public TankFactory
{
public:
	Tank* createTank() override
	{
		return new Tank56();
	}
};

//具体的创建工厂类，使用抽象工厂提供的接口，去创建具体的产品实例
class Tank96Factory : public TankFactory
{
public:
	Tank* createTank() override
	{
		return new Tank96();
	}
};