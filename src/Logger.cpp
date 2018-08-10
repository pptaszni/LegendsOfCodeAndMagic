/*
 * @author Pawel Ptasznik
 */

#include <iostream>
#include "Logger.hpp"

#define LOG_INFO
#define LOG_DEBUG

Logger::Logger(const std::string& name):
    name_(name)
{}

void Logger::info(const std::string& msg) {
    #ifdef LOG_INFO
    std::cerr << "<info> [" << name_ << "]: " << msg << std::endl;
    #endif
}

void Logger::debug(const std::string& msg) {
    #ifdef LOG_DEBUG
    std::cerr << "<debug> [" << name_ << "]: " << msg << std::endl;
    #endif
}
