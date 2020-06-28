#include "stdafx.h"
#include "StateMode.h"

using namespace StateModeSpace;

void test_state_mode()
{
	State* state = new ConcreateState1();
	Context* context = new Context();
	context->SetState(state);
	context->Request();
	context->Request();
	context->Request();
	context->Request();
}

namespace StateModeSpace {
	////////////   上下文 类  //////////////////////////////
	Context::Context()
	{
	}

	Context::~Context()
	{
	}

	void Context::SetState(State* state)
	{
		m_state = state;
	}

	void Context::Request()
	{
		m_state->Handle(this);
	}

	////////////   状态的基类  //////////////////////////////
	State::State()
	{
	}

	State::~State()
	{
	}

	////////////   状态的子类1  //////////////////////////////
	ConcreateState1::ConcreateState1()
	{
	}

	ConcreateState1::~ConcreateState1()
	{
	}

	void ConcreateState1::Handle(Context* c)
	{
		printf("%s\n", __FUNCTION__);
		c->SetState(new ConcreateState2());
	}

	////////////   状态的子类2  //////////////////////////////
	ConcreateState2::ConcreateState2()
	{
	}

	ConcreateState2::~ConcreateState2()
	{
	}

	void ConcreateState2::Handle(Context* c)
	{
		printf("%s\n", __FUNCTION__);
		c->SetState(new ConcreateState3());
	}

	////////////   状态的子类3 //////////////////////////////
	ConcreateState3::ConcreateState3()
	{
	}

	ConcreateState3::~ConcreateState3()
	{
	}

	void ConcreateState3::Handle(Context* c)
	{
		printf("%s\n", __FUNCTION__);
		c->SetState(new ConcreateState1());
	}

} // namespace StateModeSpace
