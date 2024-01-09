#include "LoggerManager.h"

std::shared_ptr<spdlog::logger> LoggerManager::logger_ = nullptr;

std::shared_ptr<spdlog::logger> LoggerManager::getLogger() {
    if (!logger_) {
        // 创建文件输出目标
        auto fileSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("Config.log");

        // 创建控制台输出目标
        auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();

        // 创建日志记录器并将输出目标添加到记录器中
        logger_ = std::make_shared<spdlog::logger>("ConfigLogger", spdlog::sinks_init_list({fileSink, consoleSink}));
        logger_->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%L] %v");

        // 设置默认日志记录器
        spdlog::set_default_logger(logger_);
    }

    return logger_;
}