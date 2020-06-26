#include "stdafx.h"
#include "BuilderMode.h"


void test_builder_mode()
{
	BuilderModeSpace::Builder* builder1 = new BuilderModeSpace::ConcreateBuilder1();
	BuilderModeSpace::Director* director1 = new BuilderModeSpace::Director(builder1);
	BuilderModeSpace::Product* product1 = director1->Construct();
	product1->ShowProduct();

	BuilderModeSpace::Builder* builder2 = new BuilderModeSpace::ConcreateBuilder2();
	BuilderModeSpace::Director* director2 = new BuilderModeSpace::Director(builder2);
	BuilderModeSpace::Product* product2 = director2->Construct();
	product2->ShowProduct();
}

namespace BuilderModeSpace {
	////////   Director 指挥者类 //////////////////////////
	Director::Director(Builder* builder)
		: m_builder(builder)
	{
	}

	Director::~Director()
	{
	}

	Product* Director::Construct()
	{
		m_builder->BuildPart1();
		m_builder->BuildPart2();
		m_builder->BuildPart3();

		return m_builder->GetProduct();
	}

	////////   Product 基类       //////////////////////////
	Product::Product()
	{
	}

	Product::~Product()
	{
	}

	void Product::ShowProduct()
	{
		printf("product info: %s\n", __FUNCTION__);
	}

	////////   Product 具体类1      //////////////////////////
	ConcreateProduct1::ConcreateProduct1()
	{
	}

	ConcreateProduct1::~ConcreateProduct1()
	{
	}

	void ConcreateProduct1::ShowProduct()
	{
		printf("product info: %s\n", __FUNCTION__);
	}

	////////   Product 具体类2      //////////////////////////
	ConcreateProduct2::ConcreateProduct2()
	{
	}

	ConcreateProduct2::~ConcreateProduct2()
	{
	}

	void ConcreateProduct2::ShowProduct()
	{
		printf("product info: %s\n", __FUNCTION__);
	}

	////////   Builder 基类      //////////////////////////
	Builder::Builder()
	{
	}

	Builder::~Builder()
	{
	}

	////////   Builder 具体类1   //////////////////////////
	ConcreateBuilder1::ConcreateBuilder1()
	{
		m_product = new ConcreateProduct1();
	}

	ConcreateBuilder1::~ConcreateBuilder1()
	{
	}

	Product* ConcreateBuilder1::GetProduct()
	{
		return m_product;
	}

	void ConcreateBuilder1::BuildPart1()
	{
		printf("ConcreateBuilder1::BuildPart1()\n");
	}

	void ConcreateBuilder1::BuildPart2()
	{
		printf("ConcreateBuilder1::BuildPart2()\n");
	}

	void ConcreateBuilder1::BuildPart3()
	{
		printf("ConcreateBuilder1::BuildPart3()\n");
	}

	////////   Builder 具体类2   //////////////////////////
	ConcreateBuilder2::ConcreateBuilder2()
	{
		m_product = new ConcreateProduct2();
	}

	ConcreateBuilder2::~ConcreateBuilder2()
	{
	}

	Product* ConcreateBuilder2::GetProduct()
	{
		return m_product;
	}

	void ConcreateBuilder2::BuildPart1()
	{
		printf("ConcreateBuilder2::BuildPart1()\n");
	}

	void ConcreateBuilder2::BuildPart2()
	{
		printf("ConcreateBuilder2::BuildPart2()\n");
	}

	void ConcreateBuilder2::BuildPart3()
	{
		printf("ConcreateBuilder2::BuildPart3()\n");
	}

}