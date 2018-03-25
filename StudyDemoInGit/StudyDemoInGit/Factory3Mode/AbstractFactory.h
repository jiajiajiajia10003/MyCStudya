#pragma once
#include "AbstractProductA.h"
#include "AbstractProductB.h"

#include "ProductA_1.h"
#include "ProductA_2.h"
#include "ProductB_1.h"
#include "ProductB_2.h"


class AbstractFactory
{
public:
    AbstractFactory(void);
    virtual ~AbstractFactory(void);
    virtual AbstractProductA* createProductAA(int type){ return nullptr;}
    virtual AbstractProductA* createProductA(){return nullptr;}
    virtual AbstractProductB* createProductB(){return nullptr;}


};

