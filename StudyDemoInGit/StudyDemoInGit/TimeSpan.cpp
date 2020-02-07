#include "stdafx.h"
#include "TimeSpan.h"

TimeSpan::TimeSpan()
	: m_begin(std::chrono::high_resolution_clock::now())
{
}

void TimeSpan::reset()
{
	m_begin = std::chrono::high_resolution_clock::now();
}

template<typename Duration>
int64_t TimeSpan::elapsed() const
{
	return std::chrono::duration_cast<Duration>(std::chrono::high_resolution_clock::now() - m_begin).count();
}

int64_t TimeSpan::elapsed_micro() const
{
	return elapsed<std::chrono::microseconds>();
}

int64_t TimeSpan::elapsed_milli() const {
	return elapsed<std::chrono::milliseconds>();
}