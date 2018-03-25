#include "stdafx.h"
#include "FactoryA_1.h"

#include <iostream>
FactoryA_1::FactoryA_1(void)
{
}


FactoryA_1::~FactoryA_1(void)
{
}

 AbstractProductA* FactoryA_1::createProductA()
{
    return new ProductA_1;
}