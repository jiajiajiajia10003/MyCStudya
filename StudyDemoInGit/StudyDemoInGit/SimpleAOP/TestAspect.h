
#include "Aspect.h"
#include "TimeElapsedAspect.h"
#include "LogAspect.h"

#include <iostream>
void foo(int a)
{
    printf("real HT function: %d\n", a);
}


void test_aspect()
{
    Invoke<LogAspect, TimeElapsedAspect>(&foo, 1); //织入方法

    Invoke<TimeElapsedAspect, LogAspect>(&foo, 1); //织入方法
}