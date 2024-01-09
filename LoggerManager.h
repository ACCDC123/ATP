#ifndef LoggerManager_H
#define LoggerManager_H

#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

class LoggerManager {
public:
    static std::shared_ptr<spdlog::logger> getLogger();

private:
    static std::shared_ptr<spdlog::logger> logger_;
};

#endif // LoggerManager_H