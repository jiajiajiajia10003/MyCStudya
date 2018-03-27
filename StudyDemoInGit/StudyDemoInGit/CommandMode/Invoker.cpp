#include "stdafx.h"
#include "Invoker.h"


Invoker::Invoker(void)
{
}


Invoker::~Invoker(void)
{
}

void Invoker::SetCommand(ICommand* cmd)
{
    m_cmd = cmd;
}
void Invoker::Action()
{
    m_cmd->Excute();
}