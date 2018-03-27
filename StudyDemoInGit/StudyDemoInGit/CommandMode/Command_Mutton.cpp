#include "stdafx.h"
#include "Command_Mutton.h"


Command_Mutton::Command_Mutton(IReceiver* receiver)
    : ICommand(receiver)
{
}


Command_Mutton::~Command_Mutton(void)
{
}

void Command_Mutton::Excute()
{
    m_receiver->DoSomething();
}