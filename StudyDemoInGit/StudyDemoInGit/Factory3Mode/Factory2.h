#pragma once
#include "abstractfactory.h"
class Factory2 :
    public AbstractFactory
{
public:
    Factory2(void);
    ~Factory2(void);

    virtual AbstractProductA* createProductA();
    virtual AbstractProductB* createProductB();
};

