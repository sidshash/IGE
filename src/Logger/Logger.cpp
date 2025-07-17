#include "Logger.h"


void Logger::Log(LogLevel level, const std::string& message, const std::string& source) {
    std::cout << FormatMessage(level, message, source) << std::endl;
}

std::string Logger::FormatMessage(LogLevel level, const std::string& message, const std::string& source) {
    std::stringstream ss;
    ss << LevelColor.at(level);
    ss << "[" << source << "] ";
    ss << "[" << ToString(level) << "] ";
    ss << message;
    ss << RESET_COLOR;
    return ss.str();
}
