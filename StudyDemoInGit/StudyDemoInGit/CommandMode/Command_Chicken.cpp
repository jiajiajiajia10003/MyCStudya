#include "stdafx.h"
#include "Command_Chicken.h"


Command_Chicken::Command_Chicken(IReceiver* receiver)
    : ICommand(receiver)
{
}


Command_Chicken::~Command_Chicken(void)
{
}

void Command_Chicken::Excute()
{
    m_receiver->DoSomething();
}
