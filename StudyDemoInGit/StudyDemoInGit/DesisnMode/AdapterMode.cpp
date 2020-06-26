#include "stdafx.h"
#include "AdapterMode.h"

void test_adapter_mode()
{
	AdapterModeSpace::IAdaptee* pAdaptee = new AdapterModeSpace::IAdaptee();
	AdapterModeSpace::ITarget* target = new AdapterModeSpace::Adapter(pAdaptee);
	target->process();
}

namespace AdapterModeSpace {
	/////////// 目标接口（新接口）//////////////

	ITarget::ITarget()
	{
	}

	ITarget::~ITarget()
	{
	}

	/////////// 遗留接口（老接口）//////////////
	IAdaptee::IAdaptee()
	{
	}

	IAdaptee::~IAdaptee()
	{
	}

	void IAdaptee::foo()
	{
		printf("%s\n", __FUNCTION__);
	}

	void IAdaptee::goo()
	{
		printf("%s\n", __FUNCTION__);
	}

	/////////// 适配接口类        //////////////
	Adapter::Adapter(IAdaptee* pAdaptee)
		: m_pAdaptee(pAdaptee)
	{
	}

	Adapter::~Adapter()
	{
	}

	void Adapter::process()
	{
		m_pAdaptee->foo();
		m_pAdaptee->goo();
	}


} // namesapce AdapterModeSpace