#pragma once
#include <list>

void test_composite_mode();

///////////////////////////////////////////////
namespace CompositeModeSpace {
	////////////   组合模式的基类  //////////////////////
	class Component
	{
	public:
		Component(std::string name);
		virtual ~Component();

		virtual void Add(Component* c)		{ }
		virtual void Remove(Component*c)	{ }
		virtual void Process()				{ }

		std::string& GetName() { return m_name; }
	protected:
		std::string m_name;
	};

	////////////   组合模式的组合节点  //////////////////////
	class Branch : public Component
	{
	public:
		Branch(std::string name);
		virtual ~Branch();

		virtual void Add(Component* c);
		virtual void Remove(Component*c);
		virtual void Process();
	private:
		std::list<Component*> m_list;
	};

	////////////   组合模式的叶子节点  //////////////////////
	class Leaf : public Component
	{
	public:
		Leaf(std::string name);
		virtual ~Leaf();

		virtual void Add(Component* c)	{ }
		virtual void Remove(Component*c){ }
		virtual void Process();

	private:
	};
} // namespace CompositeModeSpace

