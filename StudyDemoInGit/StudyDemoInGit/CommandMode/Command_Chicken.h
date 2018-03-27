#pragma once
#include "icommand.h"
class Command_Chicken :
    public ICommand
{
public:
    Command_Chicken(IReceiver* receiver);
    ~Command_Chicken(void);

    virtual void Excute();
};

