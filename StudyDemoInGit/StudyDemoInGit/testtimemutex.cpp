#include "stdafx.h"
#include "testtimemutex.h"
#include <chrono>
#include <thread>
#include <iostream>


std::timed_mutex mutex;


void work()
{
    std::chrono::milliseconds timeout(100);

    while (true)
    {   
        if (mutex.try_lock_for(timeout))
        {
            std::cout << std::this_thread::get_id() << ": do work with the mutex.\n";
            std::chrono::milliseconds sleepduration(250);
            std::this_thread::sleep_for(sleepduration);
            mutex.unlock();
        }
        else
        {
            std::cout << std::this_thread::get_id() << ": do work without the mutex.\n";
            std::chrono::milliseconds sleepduration(100);
            std::this_thread::sleep_for(sleepduration);
        }
    }
}

void test_time_mutex()
{
    std::thread th1(work);
    std::thread th2(work);

    th1.join();
    th2.join();
}