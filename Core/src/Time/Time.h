#pragma once
#include "../ENGINE_API.h"
class ENGINE_API Time
{
	static float mLastTime;
	static float mCurrentTime;
	static float mLastSecond;
	static float mDeltaTime;
	static int mFPS;
	friend class Application;
	//static void SetDeltaTime(double time);
public:
	static float GetDeltaTime();
	static int GetFPS();
};

