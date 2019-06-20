#include "stdafx.h"

#include <windows.h> // °üº¬Sleepº¯Êý
#include <iostream>


#include "ThreadPool.h"
#include "TestThreadPool.h"

void test(int i)
{
	printf("begin %d\n", i);
	Sleep(1000 * 3);
	printf("end %d\n", i);
}

void TestThreadPoolFunction()
{
	const int MAX_QUEUE = 10;
	ThreadPool pool;
	pool.setMaxQueueSize(MAX_QUEUE);
	pool.start(2);

	for (int Index = 0; Index < MAX_QUEUE ; Index++) {
		auto task = std::bind(test, Index);
		printf("insert ----------------%d\n", Index);
		pool.run(task);
	}
	getchar();
}