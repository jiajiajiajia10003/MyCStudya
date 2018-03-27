#include "stdafx.h"
#include "TestCommand.h"


TestCommand::TestCommand(void)
{
}


TestCommand::~TestCommand(void)
{
}

void TestCommand::TestFunc()
{
    Invoker* invoker = new Invoker;
    IReceiver* recerver1 = new Receiver_1;
    IReceiver* recerver2 = new Receiver_2;
    ICommand* cmd1 = new Command_Mutton(recerver1);
    ICommand* cmd2 = new Command_Chicken(recerver2);

    invoker->SetCommand(cmd1);
    invoker->Action();

    invoker->SetCommand(cmd2);
    invoker->Action();

}