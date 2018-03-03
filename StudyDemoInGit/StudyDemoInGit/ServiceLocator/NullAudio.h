#pragma once
#include "audio.h"

class NullAudio :
    public Audio
{
public:
    NullAudio(void);
    ~NullAudio(void);

    virtual void PlaySound(int soundID);
    virtual void StopSound(int soundID);
    virtual void StopSounds(void);
};

