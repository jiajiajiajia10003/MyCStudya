#pragma once
#include "Audio.h"
#include "NullAudio.h"

class Locator
{
public:
    Locator(void);
    ~Locator(void);

    static Audio& GetAudio();
    static void Provide(Audio* service);

private:
    static Audio* service_;
    static NullAudio nullService_;
};

