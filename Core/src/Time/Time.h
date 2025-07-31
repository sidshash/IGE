#pragma once
#include "../ENGINE_API.h"
class ENGINE_API Time
{
	static double mLastTime;
	static double mCurrentTime;
	static double mLastSecond;
	static double mDeltaTime;
	static int mFPS;
	friend class Application;
	//static void SetDeltaTime(double time);
public:
	static double GetDeltaTime();
	static int GetFPS();
};

