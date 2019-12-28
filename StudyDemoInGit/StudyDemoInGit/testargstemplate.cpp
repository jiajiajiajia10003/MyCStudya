#include "stdafx.h"
#include "testargstemplate.h"
#include <iostream>

void test_args_template()
{
    test_args_template1();
    test_args_template2();
    test_args_template3();
}

void test_args_template1()
{
    f();                //0
    f(1, 2);            //2
    f(1, 2.5, "hello"); //3
}

//测试可变模板的数量
template <class...T>
void f(T... args)
{
    printf("%d\n", sizeof...(args));
}

//------测试可变模板 的展开 -------------------------------
void test_args_template2()
{
    print(1, 2, 3, 4);
}
// 展开函数1--- 借助重载的递归终止函数,实现 可变模板的展开。
void print()
{
    printf("empty\n");
}

template<class T, class... args>
void print(T head, args... rest)
{
    std::cout << "parameter " << head << std::endl;
    print(rest...);
}

// 展开函数2 --- 使用初始化列表 和 逗号表达式
void test_args_template3()
{
    expand(1, 2, 3, "hello");
}

// 展开函数2 --- 使用初始化列表 和 逗号表达式
template<typename T>
void printarg(T t)
{
    std::cout << t << std::endl;
}
template<class... args>
void expand(args... a)
{
    // 
    int initialize_arr[] = { (printarg(a), 66)... };
}