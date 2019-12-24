#pragma once

#include <mutex>

void test_mutex();

class testmutex
{
public:
    testmutex(int x);
    void mul(int x);
    void div(int x);
    void both(int x, int y);
private:
    std::recursive_mutex recursivemutex;
    int i;
};

