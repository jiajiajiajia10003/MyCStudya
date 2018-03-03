#pragma once
class Audio
{
public:
    Audio(void);
    virtual ~Audio(void);
    virtual void PlaySound(int soundID) = 0;
    virtual void StopSound(int soundID) = 0;
    virtual void StopSounds(void) = 0;
};

