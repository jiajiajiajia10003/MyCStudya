#pragma once
class IReceiver
{
public:
    IReceiver(void);
    virtual ~IReceiver(void);

    virtual void DoSomething();
};

