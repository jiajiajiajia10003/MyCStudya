#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <functional>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <thread>

class ThreadPool
{
public:
	ThreadPool();
	~ThreadPool();

	typedef std::function<void()> Task;

	void start(int num_threads);
	void stop();
	void run(const Task& f);
	void setMaxQueueSize(int max_queue_size);

private:
	bool isFull();
	void runInThread();
	Task take();

	std::vector<std::thread> _threads;
	std::mutex _mutex;
	std::condition_variable _notFull;
	std::condition_variable _notEmpty;
	std::deque<Task> _queue;
	size_t _max_queue_size;
	bool _running;
};


#endif // THREADPOOL_H
