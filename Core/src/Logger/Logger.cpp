#include "Logger.h"

 std::unordered_map<LogLevel, std::string> LevelColor = {
    { LogLevel::Info,    "\033[32m" }, // Green
    { LogLevel::Warning, "\033[33m" }, // Yellow
    { LogLevel::Error,   "\033[31m" }, // Red
    { LogLevel::Debug,   "\033[36m" }, // Cyan
    { LogLevel::Event,   "\033[35m" }  // Magenta
};


 std::string RESET_COLOR = "\033[0m";

 std::string ToString(LogLevel level) {
    switch (level) {
    case LogLevel::Info: return "Info";
    case LogLevel::Warning: return "Warning";
    case LogLevel::Error: return "Error";
    case LogLevel::Debug: return "Debug";
    case LogLevel::Event: return "Event";
    }
    return "Unknown";
}

 void Logger::Log(LogLevel level, const char* message, const char*  source) {
    std::cout << FormatMessage(level, std::string(message), std::string(source)) << std::endl;
}

// void Logger::Log(LogLevel level, const Vector3& vector, const std::string& source)
//{
//    Log(level, vector.x, source);
//    Log(level, vector.y, source);
//    Log(level, vector.z, source);
//}

 std::string Logger::FormatMessage(LogLevel level, const std::string& message, const std::string& source) {
    std::stringstream ss;
    ss << LevelColor.at(level);
    ss << "[" << source << "] ";
    ss << "[" << ToString(level) << "] ";
    ss << message;
    ss << RESET_COLOR;
    return ss.str();
}
