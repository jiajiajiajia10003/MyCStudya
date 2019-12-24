#pragma once

#include <mutex>
#include <condition_variable>
#include <list>

void test_conditionvariable();

class SyncQueue
{
public:
    SyncQueue(int maxsize);
    void Put(const int& x);
    void Take(int& x);

private:
    bool IsFull() const;

    std::list<int> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_notEmpty;
    std::condition_variable m_notFull;
    int m_maxSize;
};
