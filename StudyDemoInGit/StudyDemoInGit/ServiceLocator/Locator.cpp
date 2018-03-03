#include "stdafx.h"
#include "Locator.h"

Audio* Locator::service_ = NULL;
NullAudio Locator::nullService_;

Locator::Locator(void)
{
}

Locator::~Locator(void)
{
}

Audio& Locator::GetAudio()
{
    return *service_;
}

void Locator::Provide(Audio* service)
{
    if (!service)
    {
        service = &nullService_;
    }

    service_ = service;
}