#pragma once
#include "IReceiver.h"
#include "ICommand.h"
class Invoker
{
public:
    Invoker(void);
    ~Invoker(void);

    void SetCommand(ICommand* cmd);
    void Action();
private:
    ICommand* m_cmd;
};

