#include "stdafx.h"
#include "testpackagetask.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

double func(int x)
{
    printf("%s\n", __FUNCTION__);
    std::chrono::microseconds sleeptime(1000);
    std::this_thread::sleep_for(sleeptime);

    printf("%d\n", __LINE__);
    return x + 2.5;
}

void test_package_task()
{
    // 将一个普通函数，转为packaged_task。同时，task内部，会有future
    std::packaged_task<double(int)> tsk(func);

    // 从packaged_task中，获取future。不能放在线程函数执行之后
    std::future<double> f = tsk.get_future();

    // 此处必须使用move函数，转移所有权。否则会编译出错。
    std::thread th1(std::move(tsk), 2);
    th1.detach();

    printf("get future\n");    

    double value = f.get();
    printf("value : %.3f\n", value);
}