#pragma once
#include "icommand.h"
class Command_Mutton :
    public ICommand
{
public:
    Command_Mutton(IReceiver* receiver);
    ~Command_Mutton(void);

    virtual void Excute();

};

