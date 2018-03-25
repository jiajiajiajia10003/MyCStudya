#pragma once
#include "abstractfactory.h"
class Factory1 :
    public AbstractFactory
{
public:
    Factory1(void);
    ~Factory1(void);

    virtual AbstractProductA* createProductA();
    virtual AbstractProductB* createProductB();
};

