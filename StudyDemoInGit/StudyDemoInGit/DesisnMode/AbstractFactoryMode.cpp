#include "stdafx.h"
#include "AbstractFactoryMode.h"


void test_abstract_factory_mode()
{
	AbstractFactorySpace::AbstractFactory* abstract_factory1 = new AbstractFactorySpace::ConcreateFactory1();
	abstract_factory1->CreateProductA();
	abstract_factory1->CreateProductB();

	AbstractFactorySpace::AbstractFactory* abstract_factory2 = new AbstractFactorySpace::ConcreateFactory2();
	abstract_factory2->CreateProductA();
	abstract_factory2->CreateProductB();
}

namespace AbstractFactorySpace {
	//////////  产品抽象类1  ///////////////////////////////
	AbstractProductA::AbstractProductA()
	{
	}

	AbstractProductA::~AbstractProductA()
	{
	}

	//////////  产品抽象类2  ///////////////////////////////
	AbstractProductB::AbstractProductB()
	{
	}

	AbstractProductB::~AbstractProductB()
	{
	}
	//////////  工厂抽象类  ///////////////////////////////
	AbstractFactory::AbstractFactory()
	{
	}

	AbstractFactory::~AbstractFactory()
	{
	}

	//////////  产品具体类1_1  ///////////////////////////////
	ProductA1::ProductA1()
	{
		printf("ProductA1 CPU i5\n");
	}

	ProductA1::~ProductA1()
	{
	}

	//////////  产品具体类1_2  ///////////////////////////////
	ProductA2::ProductA2()
	{
		printf("ProductA1 CPU i7\n");

	}

	ProductA2::~ProductA2()
	{
	}

	//////////  产品具体类2_1  ///////////////////////////////
	ProductB1::ProductB1()
	{
		printf("ProductB1 - DISPLAY 13'\n");

	}

	ProductB1::~ProductB1()
	{
	}

	//////////  产品具体类2_1  ///////////////////////////////
	ProductB2::ProductB2()
	{
		printf("ProductB2 - DISPLAY 15'\n");

	}

	ProductB2::~ProductB2()
	{
	}

	//////////  工厂具体类1  ///////////////////////////////
	ConcreateFactory1::ConcreateFactory1()
	{
		printf("ConcreateFactory1 - Portable PC\n");
	}

	ConcreateFactory1::~ConcreateFactory1()
	{
	}

	AbstractProductA* ConcreateFactory1::CreateProductA()
	{
		return new ProductA1();
	}

	AbstractProductB* ConcreateFactory1::CreateProductB()
	{
		return new ProductB1();
	}

	//////////  工厂具体类2  ///////////////////////////////
	ConcreateFactory2::ConcreateFactory2()
	{
		printf("ConcreateFactory2 - Game PC\n");
	}

	ConcreateFactory2::~ConcreateFactory2()
	{
	}

	AbstractProductA* ConcreateFactory2::CreateProductA()
	{
		return new ProductA2();
	}

	AbstractProductB* ConcreateFactory2::CreateProductB()
	{
		return new ProductB2();
	}

}