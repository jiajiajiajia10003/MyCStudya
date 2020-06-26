#pragma once

void test_factory_mode();

// 抽象类 ////////////////////////////////////
class IProduct
{
public:
	IProduct();
	virtual ~IProduct();

	virtual void doSomething() = 0;

private:
};

// 工厂的抽象类（对于工厂模式而言）///////////
class IFactory
{
public:
	IFactory();
	virtual ~IFactory();

	virtual IProduct* CreateFactory() = 0;
private:
};

// 具体类1 ////////////////////////////////////
class ConcreateProduct1 : public IProduct
{
public:
	ConcreateProduct1();
	virtual ~ConcreateProduct1();

	virtual void doSomething();
private:
};

// 具体类2 ////////////////////////////////////
class ConcreateProduct2 : public IProduct
{
public:
	ConcreateProduct2();
	virtual ~ConcreateProduct2();

	virtual void doSomething();
private:
};

// 具体工厂类1 ////////////////////////////////////
class ConcreateFactory1 :public IFactory
{
public:
	ConcreateFactory1();
	virtual ~ConcreateFactory1();

	virtual IProduct* CreateFactory();
private:
};

// 具体工厂类2 ////////////////////////////////////
class ConcreateFactory2 : public IFactory
{
public:
	ConcreateFactory2();
	virtual ~ConcreateFactory2();

	virtual IProduct* CreateFactory();
private:

};




