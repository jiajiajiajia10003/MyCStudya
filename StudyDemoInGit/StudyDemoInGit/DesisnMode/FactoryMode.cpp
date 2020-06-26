#include "stdafx.h"
#include "FactoryMode.h"


void test_factory_mode()
{
	IFactory* factory1 = new ConcreateFactory1();
	IProduct* splitter1 = factory1->CreateFactory();
	splitter1->doSomething();

	IFactory* factory2 = new ConcreateFactory2();
	IProduct* splitter2 = factory2->CreateFactory();
	splitter2->doSomething();
}

//////////   抽象类  ///////////////////////////////////////////
IProduct::IProduct()
{
}

IProduct::~IProduct()
{
}

////////////  工厂的抽象类   ///////////////////////////////////
IFactory::IFactory()
{
}

IFactory::~IFactory()
{
}

////////////  具体类1   ///////////////////////////////////////
ConcreateProduct1::ConcreateProduct1()
{
}

ConcreateProduct1::~ConcreateProduct1()
{
}

void ConcreateProduct1::doSomething()
{
	printf("ConcreateProduct1's split\n");
}

////////////  具体类2  /////////////////////////////////////////
ConcreateProduct2::ConcreateProduct2()
{
}

ConcreateProduct2::~ConcreateProduct2()
{
}

void ConcreateProduct2::doSomething()
{
	printf("ConcreateProduct2's split\n");
}

// 具体工厂类1 ////////////////////////////////////
ConcreateFactory1::ConcreateFactory1()
{
}

ConcreateFactory1::~ConcreateFactory1()
{
}

IProduct* ConcreateFactory1::CreateFactory()
{
	return new ConcreateProduct1();
}

// 具体工厂类2 ////////////////////////////////////
ConcreateFactory2::ConcreateFactory2()
{
}

ConcreateFactory2::~ConcreateFactory2()
{
}

IProduct* ConcreateFactory2::CreateFactory()
{
	return new ConcreateProduct2();
}