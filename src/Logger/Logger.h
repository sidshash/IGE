#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <sstream>




enum class LogLevel {
    Info,
    Warning,
    Error,
    Debug,
    Event
};

inline std::string ToString(LogLevel level) {
    switch (level) {
    case LogLevel::Info: return "Info";
    case LogLevel::Warning: return "Warning";
    case LogLevel::Error: return "Error";
    case LogLevel::Debug: return "Debug";
    case LogLevel::Event: return "Event";
    }
    return "Unknown";
}

const std::unordered_map<LogLevel, std::string> LevelColor = {
    { LogLevel::Info,    "\033[32m" }, // Green
    { LogLevel::Warning, "\033[33m" }, // Yellow
    { LogLevel::Error,   "\033[31m" }, // Red
    { LogLevel::Debug,   "\033[36m" }, // Cyan
    { LogLevel::Event,   "\033[35m" }  // Magenta
};

const std::string RESET_COLOR = "\033[0m";


class Logger {
public:
    static void Log(LogLevel level, const std::string& message, const std::string& source = "");

private:
    static std::string FormatMessage(LogLevel level, const std::string& message, const std::string& source);
};


