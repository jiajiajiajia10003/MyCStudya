#pragma once
#include "abstractfactory.h"
class SimpleFactory :
    public AbstractFactory
{
public:
    SimpleFactory(void);
    ~SimpleFactory(void);
    virtual AbstractProductA* createProductAA(int type);
};

