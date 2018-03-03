#pragma once
#include "audio.h"

class ConsoleAudio :
    public Audio
{
public:
    ConsoleAudio(void);
    ~ConsoleAudio(void);
    virtual void PlaySound(int soundID);
    virtual void StopSound(int soundID);
    virtual void StopSounds(void);
};

