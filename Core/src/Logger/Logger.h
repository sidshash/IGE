#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>
#include "../ENGINE_API.h"
#include "../Math/Vectors/Vector3.h"

enum class ENGINE_API LogLevel {
    Info,
    Warning,
    Error,
    Debug,
    Event
};

extern ENGINE_API std::string ToString(LogLevel level);

extern ENGINE_API std::unordered_map<LogLevel, std::string> LevelColor;

extern ENGINE_API std::string RESET_COLOR;


class ENGINE_API Logger {
public:
    static void Log(LogLevel level, const char* message, const char* source = "");
    //static void Log(LogLevel level, const Vector3& vector, const std::string& source = "");

private:
    static std::string FormatMessage(LogLevel level, const std::string& message, const std::string& source);
};


