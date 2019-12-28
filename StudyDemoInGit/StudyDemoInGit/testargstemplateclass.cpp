#include "stdafx.h"
#include "testargstemplateclass.h"
#include <iostream>

// 类的基本定义
template<typename First, typename...Rest>
struct Sum<First, Rest...>
{
    enum { value = Sum<First>::value +Sum<Rest...>::value};
};

// 递归终止
template<typename Last>
struct Sum<Last>
{
    enum { value = sizeof(Last) };
};

void test_args_template_class()
{
    // value的使用，必须放在enum value的定义之后。
    int size = Sum<int, double, short>::value;
    printf("size : %d \n ", size);

    using T = MakeIndexes<3>::type;  //输出为 struct IndexSeq<0,1,2>
    std::cout << typeid(T).name() << std::endl;

}
///////使用可变参数模板的工厂函数/////////////////////////////////////


ATest::ATest(int x)
    : a(x)
{
}

ATest::~ATest()
{
}

BTest::BTest(int b1, int b2)
    : m_b1(b1), m_b2(b2)
{
}

BTest::~BTest()
{
}
template<typename T, typename... Args>
T* instance(Args... args)
{
    return new T(args...);
}

void test_template_factory()
{
    // 会报错，无法解析外部符号
    //ATest* pa = Instance<ATest>(1);
    //BTest* pb = Instance<BTest>(5, 8);
}