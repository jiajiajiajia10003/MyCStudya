#pragma once
#include "IReceiver.h"
class Receiver_1 :
    public IReceiver
{
public:
    Receiver_1(void);
    ~Receiver_1(void);

    virtual void DoSomething();
};

