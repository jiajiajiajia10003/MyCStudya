#pragma once
#include "ireceiver.h"
class Receiver_2 :
    public IReceiver
{
public:
    Receiver_2(void);
    ~Receiver_2(void);
    virtual void DoSomething();
};

