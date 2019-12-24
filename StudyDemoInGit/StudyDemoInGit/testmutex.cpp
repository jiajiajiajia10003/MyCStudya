#include "stdafx.h"
#include "testmutex.h"

void test_mutex()
{
    testmutex t(4);
    //t.both(32, 23);

    std::thread th(&testmutex::both, &t, 32, 23);
    th.join();
}

testmutex::testmutex(int x = 0)
    : i(x)
{

}
void testmutex::mul(int x)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard<std::recursive_mutex> lk(recursivemutex);
    // 没有使用recursive_mutex时， 会递归调用互斥量mutex。 
    // vs会在此处产生崩溃.给出提示问题描述，但是，无法看出原因。
    printf("%d\n", __LINE__);
    i *= x;
}

void testmutex::div(int x)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard < std::recursive_mutex > lk(recursivemutex);
    if (x == 0) return;
    i /= x;
}

void testmutex::both(int x, int y)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard<std::recursive_mutex> lk(recursivemutex);
    printf("%d\n", __LINE__);
    mul(x);
    printf("%d\n", __LINE__);
    div(y);
    printf("%d\n", __LINE__);
}
