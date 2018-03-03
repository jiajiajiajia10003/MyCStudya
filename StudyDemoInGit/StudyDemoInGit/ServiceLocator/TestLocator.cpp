#include "stdafx.h"
#include "TestLocator.h"


TestLocator::TestLocator(void)
{
}


TestLocator::~TestLocator(void)
{
}

int TestLocator::testFun(void)
{
    Audio* audio1 = new ConsoleAudio();
    Locator::Provide(audio1);

    Audio* service = new LoggedWrappedAudio(Locator::GetAudio());
    Locator::Provide(service);


    Audio& audio = Locator::GetAudio();
    for (int i = 0; i < 5; ++i)
    {
        audio.PlaySound(i);
        audio.StopSound(i);
    }
    audio.StopSounds();
    return 0;
}