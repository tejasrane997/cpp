#pragma once
#include <stdio.h>
#include <ctime>
#include <mutex>

#define DEBUG(message, ...) Logger::getInstance().debug(__FILE__, __FUNCTION__, __LINE__, message, __VA_ARGS__)
#define INFO(message, ...) Logger::getInstance().info(__FILE__, __FUNCTION__, __LINE__, message, __VA_ARGS__)
#define ERROR(message, ...) Logger::getInstance().error(__FILE__, __FUNCTION__, __LINE__, message, __VA_ARGS__)
#define WARN(message, ...) Logger::getInstance().warn(__FILE__, __FUNCTION__, __LINE__, message, __VA_ARGS__)

enum LogLevel {
	DebugLevel,
	InfoLevel,
	ErrorLevel,
	WarnLevel
};

class Logger {
public:
	static Logger& getInstance()
	{
		static Logger instance;
		return instance;
	}

	void initializeLogger(LogLevel priority = DebugLevel, const char* path = "logs/log.txt")
	{
		logPriority = priority;
		filepath = path;
		printf("Log priority set to %d and Log path set to %s", priority, filepath);
	}

	template <typename... Args>
	void debug(const char* className, const char* functionName, long line, const char* message, Args... args)
	{
		log(className, functionName, line, DebugLevel, "Debug", message, args...);
	}

	template <typename... Args>
	void info(const char* className, const char* functionName, long line, const char* message, Args... args)
	{
		log(className, functionName, line, InfoLevel, "Info", message, args...);
	}

	template <typename... Args>
	void error(const char* className, const char* functionName, long line, const char* message, Args... args)
	{
		log(className, functionName, line, ErrorLevel, "Error", message, args...);
	}

	template <typename... Args>
	void warn(const char* className, const char* functionName, long line, const char* message, Args... args)
	{
		log(className, functionName, line, WarnLevel, "Warn", message, args...);
	}


private:
	static std::mutex logMutex;

	LogLevel logPriority = DebugLevel;
	FILE* file = nullptr;
	const char* filepath = "logs/log.txt";

private:

	Logger() 
	{
		fopen_s(&file, filepath, "a+");
	}

	~Logger() 
	{
		if (file) {
			fclose(file);
		}
	}

	Logger(const Logger& instance) = delete;

	Logger(Logger&& instance) = delete;

	Logger& operator=(const Logger& instance) = delete;

	Logger& operator=(Logger&& instance) = delete;

	template <typename... Args>
	void log(const char* className, const char* functionName, long line, LogLevel priority, const char* logPriorityString, const char* message, Args... args)
	{
		if (logPriority <= priority) {

			if (file) {
				std::time_t currentTime = std::time(0);
				std::tm timestamp;
				localtime_s(&timestamp, &currentTime);
				char buffer[80];
				strftime(buffer, 80, "%c", &timestamp);

				std::scoped_lock lock(logMutex);
				fprintf(file, "[%s]\t[%s][%s][%d]\t[%s]", buffer, className, functionName, line, logPriorityString);
				fprintf(file, message, args...);
				fprintf(file, "\n");
			}
		}
	}
};

std::mutex Logger::logMutex;
