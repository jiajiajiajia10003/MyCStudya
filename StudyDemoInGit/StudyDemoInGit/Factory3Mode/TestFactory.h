#pragma once
#include "AbstractFactory.h"

class TestFactory
{
public:
    TestFactory(void);
    ~TestFactory(void);

    void testSimpleFactory();
    void testFactory();
    void testAbstractFactory();
};

