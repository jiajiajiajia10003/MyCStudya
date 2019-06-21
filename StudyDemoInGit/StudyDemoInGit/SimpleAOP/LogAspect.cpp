#include "stdafx.h"

#include "LogAspect.h"

#include <iostream>

LogAspect::LogAspect()
{
}

LogAspect::~LogAspect()
{
}

void LogAspect::Before(int i)
{
    printf("entering log \n");
}

void LogAspect::After(int i)
{
	
    printf("leaving log\n");
}
