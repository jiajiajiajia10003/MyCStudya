#pragma once

void test_adapter_mode();

namespace AdapterModeSpace {
	/////////// 目标接口（新接口）//////////////
	class ITarget
	{
	public:
		ITarget();
		~ITarget();

		virtual void process() = 0;
	private:
	};

	/////////// 遗留接口（老接口）//////////////
	class IAdaptee
	{
	public:
		IAdaptee();
		~IAdaptee();

		virtual void foo();
		virtual void goo();
	private:
	};

	/////////// 适配接口类        //////////////
	class Adapter : public ITarget
	{
	public:
		Adapter(IAdaptee* pAdaptee);
		~Adapter();

		virtual void process();

	private:
		IAdaptee* m_pAdaptee;

	};

}// namespace AdapterModeSpace


