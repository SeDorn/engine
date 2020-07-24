#include "Logger.h"

#include <sstream>

void Logger::log(LogLevel level, std::string message)
{
  std::stringstream formatted;
  formatted << levelToString(level) << message;
  
  m_messages.push_back(formatted.str());
  
  if (m_enabled)
  {
    std::cout << formatted.str() << std::endl;
  }
}

void Logger::printStacktrace(int size)
{
  std::cout << "Stacktrace: " << std::endl;
  
  int printed_messages{0};
  for (unsigned long i = m_messages.size() - 1; i >= 0; i--)
  {
    if (printed_messages == size)
      break;
    
    std::cout << m_messages.at(i) << std::endl;
    printed_messages++;
  }
}

void Logger::setEnabled(bool enabled)
{
  m_enabled = enabled;
}

std::string Logger::levelToString(LogLevel level)
{
  switch (level)
  {
    case LogLevel::INFO:
      return "[INFO] ";
    case LogLevel::WARNING:
      return "[WARNING] ";
    case LogLevel::ERROR:
      return "[ERROR] ";
  }
}
