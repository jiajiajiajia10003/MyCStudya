#pragma once
#include <string>
#include <map>

void test_state_mode();

///////////////////////////////////////////////
namespace StateModeSpace {
	class State;

	////////////   上下文 类  //////////////////////////////
	class Context
	{
	public:
		Context();
		~Context();

		void SetState(State* state);
		void Request();
	private:
		State* m_state;

	};


	////////////   状态的基类  //////////////////////////////
	class State
	{
	public:
		State();
		virtual ~State();

		virtual void Handle(Context* c) = 0;
	private:

	};

	////////////   状态的子类1  //////////////////////////////
	class ConcreateState1 : public State
	{
	public:
		ConcreateState1();
		~ConcreateState1();

		virtual void Handle(Context* c);

	private:

	};	

	////////////   状态的子类2  //////////////////////////////
	class ConcreateState2 : public State
	{
	public:
		ConcreateState2();
		virtual ~ConcreateState2();

		virtual void Handle(Context* c);

	private:

	};



	////////////   状态的子类3 //////////////////////////////
	class ConcreateState3 : public State
	{
	public:
		ConcreateState3();
		virtual ~ConcreateState3();

		virtual void Handle(Context* c);

	private:

	};




} // namespace StateModeSpace

