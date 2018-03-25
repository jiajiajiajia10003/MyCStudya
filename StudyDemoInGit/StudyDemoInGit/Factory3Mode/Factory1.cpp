#include "stdafx.h"
#include "Factory1.h"


Factory1::Factory1(void)
{
}


Factory1::~Factory1(void)
{
}

AbstractProductA* Factory1::createProductA()
{
    return new ProductA_1;
}

AbstractProductB* Factory1::createProductB()
{
    return new ProductB_1;
}