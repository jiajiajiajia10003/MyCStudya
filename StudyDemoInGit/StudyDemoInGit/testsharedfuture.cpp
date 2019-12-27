#include "stdafx.h"
#include "testsharedfuture.h"
#include <thread>
#include <future>
#include <chrono>
#include <iostream>

void test_shared_future()
{
    std::future<int> f = std::async(func);

    std::shared_future<int> sf(std::move(f));

    // shared_future可以get多次。
    std::shared_future<int> sf2(sf);

    printf("v1: %d\n", sf.get());
    printf("v2: %d\n", sf2.get());
}
int func()
{
    std::chrono::milliseconds ms(2000);
    std::this_thread::sleep_for(ms);
    std::cout << "func end" << std::endl;

    return 5;
}