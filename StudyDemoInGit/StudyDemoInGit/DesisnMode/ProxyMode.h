#pragma once

void test_proxy_mode();

///////////////////////////////////////////////
namespace ProxyModeSpace {
	////////////   代理用的基类  ///////////////////////////////////
	class SubObject
	{
	public:
		SubObject();
		virtual ~SubObject();

		virtual void Request();

	private:
	};
	////////////   真正被调用的类  ///////////////////////////////////
	class RealSubObject : public SubObject
	{
	public:
		RealSubObject();
		~RealSubObject();

		virtual void Request();

	private:
	};
	////////////   提取的代理类  ///////////////////////////////////
	class Proxy : public SubObject
	{
	public:
		Proxy();
		~Proxy();

		virtual void Request();

		void Before();
		void After();
	private:
		SubObject* m_subObject;
	};


} // namespace ProxyModeSpace

