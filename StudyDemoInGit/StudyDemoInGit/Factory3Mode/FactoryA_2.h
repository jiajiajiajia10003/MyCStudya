#pragma once
#include "abstractfactory.h"
class FactoryA_2 :
    public AbstractFactory
{
public:
    FactoryA_2(void);
    ~FactoryA_2(void);
    virtual AbstractProductA* createProductA();

};

