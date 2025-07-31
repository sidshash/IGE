#include "Time.h"

float Time::mDeltaTime   = 0.0f;
float Time::mCurrentTime = 0.0f;
float Time::mLastSecond  = 0.0f;
float Time::mLastTime    = 0.0f;
int    Time::mFPS         = 0;

float Time::GetDeltaTime()
{
    return mDeltaTime;
}

int Time::GetFPS() {
    return mFPS;
}



