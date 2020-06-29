#pragma once
#include <string>

void test_memento_mode();

///////////////////////////////////////////////
namespace MementoModeSpace {
	

	////////////   备忘录 类  //////////////////////////////
	class Memento
	{
	public:
		Memento();
		~Memento();

		void SetState(const std::string& state);
		std::string GetState();

	private:
		std::string m_state;
	};

	////////////   创建备忘录的类 //////////////////////////////
	class Originator
	{
	public:
		Originator(std::string state);
		~Originator();

		void SetMemento(Memento* mem);
		Memento* CreateMemento();

		void SetState(const std::string& state);
		std::string& GetState();
		void ShowState();
	private:
		std::string m_state;
	};
	
	////////////   保存备忘录的类  //////////////////////////////
	class Caretaker
	{
	public:
		Caretaker();
		~Caretaker();

		void SetMemento(Memento* mem);
		Memento* GetMemento();

	private:
		Memento* m_memento;
	};

} // namespace MementoModeSpace

