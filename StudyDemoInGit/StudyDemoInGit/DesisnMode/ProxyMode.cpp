#include "stdafx.h"
#include "ProxyMode.h"


void test_proxy_mode()
{
	ProxyModeSpace::Proxy* proxy = new ProxyModeSpace::Proxy();
	proxy->Request();
}

namespace ProxyModeSpace {
	////////////   代理用的基类  ///////////////////////////////////
	SubObject::SubObject()
	{
	}

	SubObject::~SubObject()
	{
	}

	void SubObject::Request()
	{

	}
	////////////   真正被调用的类  ///////////////////////////////////
	RealSubObject::RealSubObject()
	{
	}

	RealSubObject::~RealSubObject()
	{
	}
	void RealSubObject::Request()
	{
		printf("%s\n", __FUNCTION__);
	}

	////////////   提取的代理类  ///////////////////////////////////
	Proxy::Proxy()
	{
		m_subObject = new RealSubObject();
	}

	Proxy::~Proxy()
	{
	}

	void Proxy::Request()
	{
		printf("%s\n", __FUNCTION__);
		Before();
		m_subObject->Request();
		After();
	}

	void Proxy::Before()
	{
		printf("%s\n", __FUNCTION__);
	}

	void Proxy::After()
	{
		printf("%s\n", __FUNCTION__);
	}


} // namespace ProxyModeSpace
