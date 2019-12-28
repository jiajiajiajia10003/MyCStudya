#pragma once
/*
测试的是“可变参数模板函数”
*/
////////方式1： 递归 + 特化方式，展开参数包///////////////////////////////////
void test_args_template_class();

//  声明
template<typename... Args>
struct Sum
{

};

//////////方式2：继承方式，展开参数包//////////////////////////
//整型序列的定义
template<int...>
struct IndexSeq {};

//继承方式，开始展开参数包
template<int N, int ... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

//模板特化，终止展开参数包的条件
template<int... Indexes>
struct MakeIndexes<0, Indexes...> {
    typedef IndexSeq<Indexes...> type;
};


///////使用可变参数模板的工厂函数/////////////////////////////////////
class ATest
{
public:
	ATest(int x);
	~ATest();

private:
	int a;
};
class BTest
{
public:
	BTest(int b1, int b2);
	~BTest();

private:
	int m_b1;
	int m_b2;
};

void test_template_factory();
template<typename T, typename... Args>
T* Instance(Args... args);