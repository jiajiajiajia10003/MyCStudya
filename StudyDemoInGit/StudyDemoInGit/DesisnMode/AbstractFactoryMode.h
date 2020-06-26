#pragma once

void test_abstract_factory_mode();
namespace AbstractFactorySpace {

	//////////  产品抽象类1  ///////////////////////////////
	class AbstractProductA
	{
	public:
		AbstractProductA();
		virtual ~AbstractProductA();

	private:
	};

	//////////  产品抽象类2  ///////////////////////////////
	class AbstractProductB
	{
	public:
		AbstractProductB();
		virtual ~AbstractProductB();

	private:
	};

	//////////  工厂抽象类  ///////////////////////////////
	class AbstractFactory
	{
	public:
		AbstractFactory();
		virtual ~AbstractFactory();

		virtual AbstractProductA* CreateProductA() = 0;
		virtual AbstractProductB* CreateProductB() = 0;

	private:
	};

	//////////  产品具体类1_1  ///////////////////////////////
	class ProductA1 : public AbstractProductA
	{
	public:
		ProductA1();
		virtual ~ProductA1();

	private:
	};

	//////////  产品具体类1_2  ///////////////////////////////
	class ProductA2 : public AbstractProductA
	{
	public:
		ProductA2();
		virtual ~ProductA2();

	private:
	};

	//////////  产品具体类2_1  ///////////////////////////////
	class ProductB1 : public AbstractProductB
	{
	public:
		ProductB1();
		virtual ~ProductB1();

	private:
	};

	//////////  产品具体类2_1  ///////////////////////////////
	class ProductB2 : public AbstractProductB
	{
	public:
		ProductB2();
		virtual ~ProductB2();

	private:

	};

	//////////  工厂具体类1  ///////////////////////////////
	class ConcreateFactory1 : public AbstractFactory
	{
	public:
		ConcreateFactory1();
		virtual ~ConcreateFactory1();

		virtual AbstractProductA* CreateProductA();
		virtual AbstractProductB* CreateProductB();

	private:
	};

	//////////  工厂具体类2  ///////////////////////////////
	class ConcreateFactory2 : public AbstractFactory
	{
	public:
		ConcreateFactory2();
		~ConcreateFactory2();

		virtual AbstractProductA* CreateProductA();
		virtual AbstractProductB* CreateProductB();
	private:
	};

}
