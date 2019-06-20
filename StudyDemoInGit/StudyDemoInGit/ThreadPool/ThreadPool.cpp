#include "stdafx.h"

#include "ThreadPool.h"

ThreadPool::ThreadPool()
	: _running(false)
	, _max_queue_size(10)
{
}

ThreadPool::~ThreadPool()
{
	if (_running) {
		stop();
	}
}

void ThreadPool::start(int num_threads)
{
	_running = true;
	_threads.reserve(num_threads);

	for (int Index = 0; Index < num_threads ; Index++) {
		_threads.push_back(std::thread(&ThreadPool::runInThread, this));
	}
}

void ThreadPool::stop()
{
	{
		std::unique_lock<std::mutex> lock(_mutex);
		// 标识位置为false
		_running = false;
		// 使用非空条件变量,通知全部
		_notEmpty.notify_all();
	}
	// 关闭线程
	for (size_t Index = 0; Index < _threads.size(); Index++) {
		_threads[Index].join();
	}
}

void ThreadPool::run(const Task& f)
{
	// 如果没有设置线程数量，则当做是单线程，直接执行任务
	if (_threads.empty()) {
		f();
	}
	std::unique_lock<std::mutex> lock(_mutex);
	while (isFull()) {
		// 会死等，但是会释放mutex
		_notFull.wait(lock);
	}
	_queue.push_back(f);
	_notEmpty.notify_one();
}

void ThreadPool::setMaxQueueSize(int max_queue_size)
{
	_max_queue_size = max_queue_size;
}

bool ThreadPool::isFull()
{
	return _max_queue_size > 0 && _queue.size() >= _max_queue_size;
}

void ThreadPool::runInThread()
{
	try {
		while (_running)
		{
			Task task = take();
			if (task) {
				task();
			}
		}
	}
	catch (const std::exception& e) {
		printf("exception reason1 : %s\n", e.what());		
	}
	catch (...) {
		printf("exception\n");
	}
}

ThreadPool::Task ThreadPool::take()
{
	std::unique_lock<std::mutex> lock(_mutex);
	// 死等队列有任务
	while (_queue.empty() && _running)
	{
		// 会死等，但是会释放mutex
		_notEmpty.wait(lock);
	}

	Task task;
	// 取出任务
	if (!_queue.empty()) {
		task = _queue.front();
		_queue.pop_front();
	}
	// 取出任务后，队列中如果还有任务，可以使用非满条件变量，通知
	if (_queue.size() > 0) {
		_notFull.notify_one();
	}
	return task;
}
