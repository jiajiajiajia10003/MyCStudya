#include "stdafx.h"
#include "IReceiver.h"

#include <iostream>
IReceiver::IReceiver(void)
{
}


IReceiver::~IReceiver(void)
{
}

void IReceiver::DoSomething()
{
    std::cout << __FUNCTION__ << std::endl;
}