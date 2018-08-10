#pragma once

/*
 * @author Pawel Ptasznik
 */

#include <string>

class Logger {
public:
    Logger() = delete;
    Logger(const std::string& name);
    void info(const std::string& msg);
    void debug(const std::string& msg);
private:
    std::string name_;
};
