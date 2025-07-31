#include "Time.h"

double Time::mDeltaTime   = 0.0f;
double Time::mCurrentTime = 0.0f;
double Time::mLastSecond  = 0.0f;
double Time::mLastTime    = 0.0f;
int    Time::mFPS         = 0;

double Time::GetDeltaTime()
{
    return mDeltaTime;
}

int Time::GetFPS() {
    return mFPS;
}



