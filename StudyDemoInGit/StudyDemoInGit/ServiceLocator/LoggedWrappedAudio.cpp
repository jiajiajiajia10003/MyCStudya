#include "stdafx.h"
#include "LoggedWrappedAudio.h"

//#include <windows.h>

LoggedWrappedAudio::LoggedWrappedAudio(Audio& wrapped)
    :wrapped_(wrapped)
{
}


LoggedWrappedAudio::~LoggedWrappedAudio(void)
{
}


void LoggedWrappedAudio::PlaySound(int soundID)
{
    Log(__FUNCTION__, soundID);
    wrapped_.PlaySound(soundID);
}


void LoggedWrappedAudio::StopSound(int soundID)
{
    Log(__FUNCTION__, soundID);
    wrapped_.StopSound(soundID);
}


void LoggedWrappedAudio::StopSounds(void)
{
    Log(__FUNCTION__, 0);
    wrapped_.StopSounds();
}

void LoggedWrappedAudio::Log(const std::string message, int id)
{
    std::stringstream ss;
    ss << "Log: " <<message << ", " << id;
    std::cout << ss.str().c_str() << std::endl;
}