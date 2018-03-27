#pragma once
#include "IReceiver.h"

class ICommand
{
public:
    ICommand(IReceiver* receiver);
    virtual ~ICommand(void);

    virtual void Excute();

    IReceiver* m_receiver;
};

