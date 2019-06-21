#include "stdafx.h"

#include "TimeElapsedAspect.h"

#include <iostream>

TimeElapsedAspect::TimeElapsedAspect()
    : m_last_time(0.0f)
{
}

TimeElapsedAspect::~TimeElapsedAspect()
{
}

void TimeElapsedAspect::Before(int i)
{
    printf("start time \n");
	m_t = time(NULL);
}

void TimeElapsedAspect::After(int i)
{
	time_t t = time(NULL);
	//printf("time elapsed : %d\n", t - m_t);
    printf("end timer\n");
}
