#pragma once
#include <string>
#include <map>

void test_flyweight_mode();

///////////////////////////////////////////////
namespace FlyweightModeSpace {
	class Flyweight;
	////////////   享元的工厂类  //////////////////////////////
	class FlyweightFactory
	{
	public:
		FlyweightFactory();
		~FlyweightFactory();

		Flyweight* GetFlyweight(const std::string& name);

	private:
		std::map<std::string, Flyweight*> m_Flyweights;
	};

	////////////   享元的基类  //////////////////////////////
	class Flyweight
	{
	public:
		Flyweight(std::string key);
		virtual ~Flyweight();

		virtual void Process() = 0;

	protected:
		std::string m_key;

	};



	////////////   享元的子类1  //////////////////////////////
	class ConcreateFlyweight1 : public Flyweight
	{
	public:
		ConcreateFlyweight1(std::string key);
		virtual ~ConcreateFlyweight1();

		virtual void Process();

	private:

	};


	////////////   享元的子类2  //////////////////////////////
	class ConcreateFlyweight2 : public Flyweight
	{
	public:
		ConcreateFlyweight2(std::string key);
		virtual ~ConcreateFlyweight2();

		virtual void Process();

	private:

	};



} // namespace FlyweightModeSpace

