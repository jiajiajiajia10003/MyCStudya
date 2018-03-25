#pragma once
class AbstractProductB
{
public:
    AbstractProductB(void);
    virtual ~AbstractProductB(void);

    virtual void operation(void) = 0;
};

