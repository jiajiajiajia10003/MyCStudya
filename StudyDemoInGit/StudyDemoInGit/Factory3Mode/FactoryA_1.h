#pragma once
#include "abstractfactory.h"
class FactoryA_1 :
    public AbstractFactory
{
public:
    FactoryA_1(void);
    ~FactoryA_1(void);
    virtual AbstractProductA* createProductA();

};

