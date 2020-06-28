#include "stdafx.h"
#include "FlyweightMode.h"

using namespace FlyweightModeSpace;

void test_flyweight_mode()
{
	FlyweightFactory* factory = new FlyweightFactory();
	Flyweight* flyweight1 = factory->GetFlyweight("ms_font");
	flyweight1->Process();
}

namespace FlyweightModeSpace {
	////////////   享元的工厂类  //////////////////////////////
	FlyweightFactory::FlyweightFactory()
	{
	}

	FlyweightFactory::~FlyweightFactory()
	{
	}


	FlyweightModeSpace::Flyweight* FlyweightFactory::GetFlyweight(const std::string& name)
	{
		auto iter = m_Flyweights.find(name);
		if (iter != m_Flyweights.end())
		{
			return m_Flyweights[name];
		} 
		else
		{
			Flyweight* flyweight = new ConcreateFlyweight1(name);
			m_Flyweights[name] = flyweight;
			return flyweight;
		}
	}

	////////////   享元的基类  //////////////////////////////
	Flyweight::Flyweight(std::string key)
		: m_key(key)
	{
	}

	Flyweight::~Flyweight()
	{
	}
	////////////   享元的子类1  //////////////////////////////
	ConcreateFlyweight1::ConcreateFlyweight1(std::string key)
		: Flyweight(key)
	{
	}

	ConcreateFlyweight1::~ConcreateFlyweight1()
	{
	}

	void ConcreateFlyweight1::Process()
	{
		printf("%s\n", m_key.c_str());
	}

	////////////   享元的子类2  //////////////////////////////
	ConcreateFlyweight2::ConcreateFlyweight2(std::string key)
		: Flyweight(key)
	{
	}

	ConcreateFlyweight2::~ConcreateFlyweight2()
	{
	}

	void ConcreateFlyweight2::Process()
	{

	}

} // namespace FlyweightModeSpace
