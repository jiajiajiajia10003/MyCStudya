#include "stdafx.h"
#include "SimpleFactory.h"


SimpleFactory::SimpleFactory(void)
{
}


SimpleFactory::~SimpleFactory(void)
{
}

AbstractProductA* SimpleFactory::createProductAA(int type)
{
    AbstractProductA* ret = nullptr;
    switch (type)
    {
    case 1 :
        ret = new ProductA_1;
        break;
    case 2:
        ret = new ProductA_2;
        break;
    default:
        break;
    }

    return ret;
}