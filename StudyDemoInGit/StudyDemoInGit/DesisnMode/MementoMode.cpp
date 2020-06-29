#include "stdafx.h"
#include "MementoMode.h"

using namespace MementoModeSpace;

void test_memento_mode()
{
	// 初始化对象， 状态为"Old"
	Originator* ori = new Originator("Old");
	ori->ShowState();

	// 建立并保存Memento
	Caretaker* taker = new Caretaker();
	taker->SetMemento(ori->CreateMemento());

	// 改变状态为"new"
	ori->SetState("New");
	ori->ShowState();

	// 恢复状态
	ori->SetMemento(taker->GetMemento());
	ori->ShowState();
}

namespace MementoModeSpace {
	////////////   备忘录 类  //////////////////////////////
	Memento::Memento()
	{
	}

	Memento::~Memento()
	{
	}

	void Memento::SetState(const std::string& state)
	{
		m_state = state;
	}

	std::string Memento::GetState()
	{
		return m_state;
	}


	////////////   创建备忘录的类 //////////////////////////////
	Originator::Originator(std::string state)
		: m_state(state)
	{
	}

	Originator::~Originator()
	{
	}

	void Originator::SetMemento(Memento* mem)
	{
		m_state = mem->GetState();
	}

	MementoModeSpace::Memento* Originator::CreateMemento()
	{
		// 此处可以考虑序列化多个state值
		Memento* mem = new Memento();
		mem->SetState(m_state);

		return mem;
	}

	void Originator::SetState(const std::string& state)
	{
		m_state = state;
	}

	std::string& Originator::GetState()
	{
		return m_state;
	}

	void Originator::ShowState()
	{
		printf("current state : %s\n", m_state.c_str());
	}

	////////////   保存备忘录的类  //////////////////////////////
	Caretaker::Caretaker()
	{
	}

	Caretaker::~Caretaker()
	{
	}

	void Caretaker::SetMemento(Memento* mem)
	{
		m_memento = mem;
	}

	MementoModeSpace::Memento* Caretaker::GetMemento()
	{
		return m_memento;
	}

} // namespace MementoModeSpace
