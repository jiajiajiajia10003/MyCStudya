#include "stdafx.h"
#include "testconditionvariable.h"
#include <iostream>
#include <chrono>
#include <thread>

SyncQueue s(5);

void put_run()
{
    for (size_t i = 0; i < 7; i++)
    {
        s.Put(i);
        std::chrono::milliseconds sleepduration(250);
        std::this_thread::sleep_for(sleepduration);
    }
    for (size_t i = 0; i < 7; i++)
    {
        s.Put(i);
        std::chrono::milliseconds sleepduration(50);
        std::this_thread::sleep_for(sleepduration);
    }
}

void take_run()
{
    for (size_t i = 0; i < 14; i++)
    {
        int x = 0;
        s.Take(x);
        std::chrono::milliseconds sleepduration(100);
        std::this_thread::sleep_for(sleepduration);
    }
}
void test_conditionvariable()
{
    std::thread th1(put_run);
    std::thread th2(take_run);

    th1.join();
    th2.join();
       
    

}

SyncQueue::SyncQueue(int maxsize)
    :m_maxSize(maxsize)
{
}

void SyncQueue::Put(const int& x)
{
    printf("Enter:%s\n", __FUNCTION__);
    std::unique_lock<std::mutex> lk(m_mutex);
    // 如果第二参数lambda函数，返回为false，则会继续等待，且释放mutex
    m_notFull.wait(lk, [this] { return !IsFull(); });
    
    m_queue.push_back(x);
    m_notEmpty.notify_one();
    printf("LEAVE:%s\n", __FUNCTION__);

}
void SyncQueue::Take(int& x)
{
    printf("      Enter:%s\n", __FUNCTION__); 
    std::unique_lock<std::mutex> lk(m_mutex);
    // 如果第二参数lambda函数，返回为false，则会继续等待，且释放mutex
    m_notEmpty.wait(lk, [this]() { return !m_queue.empty(); });
    x = m_queue.front();
    m_queue.pop_front();
    printf("      LEAVE:%s\n", __FUNCTION__);
}

bool SyncQueue::IsFull() const
{
    return m_queue.size() == m_maxSize;
}