#pragma once
void test_args_template();
//测试可变模板的数量
void test_args_template1();
//------测试可变模板 的展开
void test_args_template2();
// 展开函数2 --- 使用初始化列表 和 逗号表达式
void test_args_template3();

template <class...T>
void f(T... args);

// 展开函数1--- 借助重载的递归终止函数,实现 可变模板的展开。
void print();

template<class T, class... args>
void print(T head, args... rest);

// 展开函数2 --- 使用初始化列表 和 逗号表达式
template<typename T>
void printarg(T t);

template<class... args>
void expand(args... a);



