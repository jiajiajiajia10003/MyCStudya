#include "stdafx.h"
#include "CommandMode.h"

using namespace CommandModeSpace;

void test_command_mode()
{	
	// 创建2个接收者对象，并关联2个Command对象
	IReceiver* recv1 = new Receiver1();
	IReceiver* recv2 = new Receiver2();

	// 创建2个Command对象，同时保存2个接收者对象
	ICommand* cmd1 = new Command1(recv1);
	ICommand* cmd2 = new Command2(recv2);

	// 设置完command和receiver的关联关系后， 发起请求
	// 创建请求者1
	Invoker* invoker1 = new Invoker();
	invoker1->SetCommand(cmd1);
	invoker1->Action();

	// 创建请求者2
	Invoker* invoker2 = new Invoker();
	invoker2->SetCommand(cmd2);
	invoker2->Action();
}

namespace CommandModeSpace {
	////////////   Command 抽象类  //////////////////////////////
	ICommand::ICommand(IReceiver* receiver)
		: m_receiver(receiver)
	{
	}

	ICommand::~ICommand()
	{
	}

	void ICommand::Excute()
	{
		printf("%s\n", __FUNCTION__);
	}

	////////////   接收者  抽象类  //////////////////////////////
	IReceiver::IReceiver()
	{
	}

	IReceiver::~IReceiver()
	{
	}

	void IReceiver::DoSomething()
	{
		printf("%s\n", __FUNCTION__);
	}

	////////////   Command 具体类1  //////////////////////////////
	Command1::Command1(IReceiver* receiver)
		: ICommand(receiver)
	{
	}

	Command1::~Command1()
	{
	}

	void Command1::Excute()
	{
		printf("%s\n", __FUNCTION__);
		m_receiver->DoSomething();
	}

	////////////   Command 具体类2  //////////////////////////////
	Command2::Command2(IReceiver* receiver)
		: ICommand(receiver)
	{
	}

	Command2::~Command2()
	{
	}

	void Command2::Excute()
	{
		printf("%s\n", __FUNCTION__);
		m_receiver->DoSomething();
	}

	////////////   接收者  具体类1  //////////////////////////////
	Receiver1::Receiver1()
	{
	}

	Receiver1::~Receiver1()
	{
	}

	void Receiver1::DoSomething()
	{
		printf("%s\n", __FUNCTION__);
	}

	////////////   接收者  具体类2  //////////////////////////////
	Receiver2::Receiver2()
	{
	}

	Receiver2::~Receiver2()
	{
	}

	void Receiver2::DoSomething()
	{
		printf("%s\n", __FUNCTION__);
	}

	////////////   请求者           //////////////////////////////
	Invoker::Invoker()
	{
	}

	Invoker::~Invoker()
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

} // namespace CommandModeSpace
