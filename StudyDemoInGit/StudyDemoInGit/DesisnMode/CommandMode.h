#pragma once


void test_command_mode();

///////////////////////////////////////////////
namespace CommandModeSpace {
	class IReceiver;
	////////////   Command 抽象类  //////////////////////////////
	class ICommand
	{
	public:
		ICommand(IReceiver* receiver);
		virtual ~ICommand();

		virtual void Excute();
	protected:
		IReceiver* m_receiver;
	};

	////////////   接收者  抽象类  //////////////////////////////
	class IReceiver
	{
	public:
		IReceiver();
		virtual ~IReceiver();

		virtual void DoSomething();
	private:
	};

	////////////   Command 具体类1  //////////////////////////////
	class Command1 : public ICommand
	{
	public:
		Command1(IReceiver* receiver);
		~Command1();

		virtual void Excute();
	private:
	};

	////////////   Command 具体类2  //////////////////////////////
	class Command2 : public ICommand
	{
	public:
		Command2(IReceiver* receiver);
		~Command2();

		virtual void Excute();
	private:

	};

	////////////   接收者  具体类1  //////////////////////////////
	class Receiver1 : public IReceiver
	{
	public:
		Receiver1();
		virtual ~Receiver1();

		virtual void DoSomething();
	private:
	};

	////////////   接收者  具体类2  //////////////////////////////
	class Receiver2 : public IReceiver
	{
	public:
		Receiver2();
		~Receiver2();

		virtual void DoSomething();
	private:
	};

	////////////   请求者           //////////////////////////////
	class Invoker
	{
	public:
		Invoker();
		~Invoker();

		void SetCommand(ICommand* cmd);
		void Action();
	private:
		ICommand* m_cmd;
	};



} // namespace CommandModeSpace

