#include "stdafx.h"
#include "Factory3Mode\SimpleFactory.h"


ProductA_1* SimpleFactory::createProduct(int type)
{
    switch (type)
    {
    case 1:
        return new ProductA_1; 
        break;
    case 2:
        break;
    default:
        ;
    }
    return NULL;
}
