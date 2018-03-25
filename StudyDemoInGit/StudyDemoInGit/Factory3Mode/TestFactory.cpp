#include "stdafx.h"
#include "TestFactory.h"
#include "SimpleFactory.h"
#include "AbstractProductA.h"
#include "FactoryA_1.h"
#include "FactoryA_2.h"
#include "Factory1.h"
#include "Factory2.h"

TestFactory::TestFactory(void)
{
}


TestFactory::~TestFactory(void)
{
}

void TestFactory::testSimpleFactory()
{
    AbstractFactory* factory = new SimpleFactory();

    AbstractProductA* product = factory->createProductAA(1);
    product->operation();
    delete product;
    product = nullptr;

    product = factory->createProductAA(2);
    product->operation();
    delete product;
    product = nullptr;
   
    delete factory; 
    factory = nullptr;

}

void TestFactory::testFactory()
{
    AbstractFactory* f1  = new FactoryA_1;
    AbstractProductA* p1 =  f1->createProductA();
    p1->operation();
    delete p1;
    p1 = nullptr;

    AbstractFactory* f2 = new FactoryA_2;
    AbstractProductA* p2 = f2->createProductA();
    p2->operation();
    delete p2;
    p2 = nullptr;

    delete f2;
    f2 = nullptr;
    delete f1;
    f1 = nullptr;
}

void TestFactory::testAbstractFactory()
{
    Factory1* f1 = new Factory1;
    AbstractProductA* pa1 = f1->createProductA();
    AbstractProductB* pb1 = f1->createProductB();
    pa1->operation();
    pb1->operation();

    Factory2* f2 = new Factory2;
    AbstractProductA* pa2 = f2->createProductA();
    AbstractProductB* pb2 = f2->createProductB();
    pa2->operation();
    pb2->operation();
}