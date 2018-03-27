#include "stdafx.h"
#include "ICommand.h"


ICommand::ICommand(IReceiver* receiver)
    : m_receiver(receiver)
{
}

ICommand::~ICommand(void)
{
}

void ICommand::Excute()
{
    m_receiver->DoSomething();
}