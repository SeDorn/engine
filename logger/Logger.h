#ifndef ENGINE_LOGGER_H
#define ENGINE_LOGGER_H

#include <iostream>
#include <vector>

enum class LogLevel
{
  INFO,
  WARNING,
  ERROR
};

class Logger
{
  public:
    void log(LogLevel level, std::string message);
    
    void printStacktrace(int size);
    void setEnabled(bool enabled);
  
    static Logger& instance()
    {
      static Logger instance;
      return instance;
    }
  
    Logger(Logger const&) = delete;
    void operator=(Logger const&) = delete;
  private:
    Logger() = default;
    
    std::string levelToString(LogLevel level);
    
    std::vector<std::string> m_messages;
    bool m_enabled{false};
};

#endif
