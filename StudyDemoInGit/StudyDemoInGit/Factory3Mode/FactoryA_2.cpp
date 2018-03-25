#include "stdafx.h"
#include "FactoryA_2.h"
#include <iostream>

FactoryA_2::FactoryA_2(void)
{
}


FactoryA_2::~FactoryA_2(void)
{
}
AbstractProductA* FactoryA_2::createProductA()
{
    return new ProductA_2;
}