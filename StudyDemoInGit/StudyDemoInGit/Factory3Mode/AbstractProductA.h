#pragma once
class AbstractProductA
{
public:
    AbstractProductA(void);
    virtual ~AbstractProductA(void);
    virtual void operation(void) = 0;
};

