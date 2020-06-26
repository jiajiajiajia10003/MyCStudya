#pragma once

void test_builder_mode();

namespace BuilderModeSpace {
	class Builder;
	class Product;

	////////   Director 指挥者类 //////////////////////////
	class Director
	{
	public:
		Director(Builder* builder);
		~Director();
		Product* Construct();

	private:
		Builder* m_builder;
	};
	////////   Product 基类       //////////////////////////
	class Product
	{
	public:
		Product();
		virtual ~Product();

		virtual void ShowProduct();

	private:
	};

	////////   Product 具体类1      //////////////////////////
	class ConcreateProduct1 : public Product
	{
	public:
		ConcreateProduct1();
		~ConcreateProduct1();
		virtual void ShowProduct();

	private:
	};


	////////   Product 具体类2      //////////////////////////
	class ConcreateProduct2 : public Product
	{
	public:
		ConcreateProduct2();
		~ConcreateProduct2();
		virtual void ShowProduct();

	private:
	};

	////////   Builder 基类      //////////////////////////
	class Builder
	{
	public:
		Builder();
		virtual ~Builder();
		virtual Product* GetProduct() = 0;

		virtual void BuildPart1() = 0;
		virtual void BuildPart2() = 0;
		virtual void BuildPart3() = 0;

	protected:
		Product* m_product;
	private:
	};

	////////   Builder 具体类1   //////////////////////////
	class ConcreateBuilder1 : public Builder
	{
	public:
		ConcreateBuilder1();
		virtual ~ConcreateBuilder1();
		virtual Product* GetProduct();

		virtual void BuildPart1();
		virtual void BuildPart2();
		virtual void BuildPart3();
	private:

	};

	////////   Builder 具体类2   //////////////////////////
	class ConcreateBuilder2 : public Builder
	{
	public:
		ConcreateBuilder2();
		virtual ~ConcreateBuilder2();
		virtual Product* GetProduct();

		virtual void BuildPart1();
		virtual void BuildPart2();
		virtual void BuildPart3();
	private:

	};

}// namespace BuilderModeSpace