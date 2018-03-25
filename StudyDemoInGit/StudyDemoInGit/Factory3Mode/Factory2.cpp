#include "stdafx.h"
#include "Factory2.h"


Factory2::Factory2(void)
{
}


Factory2::~Factory2(void)
{
}

AbstractProductA* Factory2::createProductA()
{
    return new ProductA_2;
}

AbstractProductB* Factory2::createProductB()
{
    return new ProductB_2;
}