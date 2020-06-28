#include "stdafx.h"
#include "CompositeMode.h"

using namespace CompositeModeSpace;

void test_composite_mode()
{
	Branch root("root");
	Branch treeNode1("treeNode1");
	Branch treeNode2("treeNode2");
	Branch treeNode3("treeNode3");
	Branch treeNode4("treeNode4");

	Leaf leaf1("leaf1");
	Leaf leaf2("leaf2");

	root.Add(&treeNode1);
	treeNode1.Add(&treeNode2);
	treeNode2.Add(&leaf1);

	root.Add(&treeNode3);
	treeNode3.Add(&treeNode4);
	treeNode4.Add(&leaf2);

	root.Process();
}

namespace CompositeModeSpace {
	////////////   代理用的基类  ///////////////////////////////////
	Component::Component(std::string name)
		: m_name(name)
	{
	}

	Component::~Component()
	{
	}


	////////////   组合模式的组合节点  //////////////////////
	Branch::Branch(std::string name)
		: Component(name)
	{
	}

	Branch::~Branch()
	{
	}

	void Branch::Add(Component* c)
	{
		m_list.push_back(c);
	}

	void Branch::Remove(Component*c)
	{
		auto iter = m_list.end();
		for (; iter != m_list.end(); ++iter)
		{
			std::string s1 = (*iter)->GetName();
			std::string s2 = c->GetName();
			if (0 == s2.compare(s1))
			{
				m_list.erase(iter);
				break;
			}
		}
	}

	void Branch::Process()
	{
		// 处理当前节点
		printf("%s\n", m_name.c_str());
		auto it = m_list.begin();

		// 处理成员节点
		while (it != m_list.end())
		{
			(*it)->Process();
			++it;
		}

	}

	////////////   组合模式的叶子节点  //////////////////////
	Leaf::Leaf(std::string name)
		: Component(name)
	{
	}

	Leaf::~Leaf()
	{
	}

	void Leaf::Process()
	{
		printf("%s\n", m_name.c_str());
	}

} // namespace CompositeModeSpace
