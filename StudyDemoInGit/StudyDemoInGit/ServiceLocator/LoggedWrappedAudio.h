#pragma once
#include "Audio.h"

#include <iostream>
#include <sstream>

class LoggedWrappedAudio :
    public Audio
{
public:
    LoggedWrappedAudio(Audio& wrapped);
    ~LoggedWrappedAudio(void);

    virtual void PlaySound(int soundID);
    virtual void StopSound(int soundID);
    virtual void StopSounds(void);
private:
    void Log(const std::string message, int id);
    Audio& wrapped_;
};

