#pragma once


#include <chrono>

class TimeSpan
{
public:
	TimeSpan();

	void reset();

	template<typename Duration>
	int64_t elapsed() const;

	int64_t elapsed_micro() const;
	int64_t elapsed_milli() const;
private:
	std::chrono::time_point<std::chrono::high_resolution_clock> m_begin;
};

