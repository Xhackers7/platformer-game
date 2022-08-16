#include "core/Log.hpp"

Log::Level Log::m_currentLevel;

void Log::setLevel(Level logLevel)
{
  m_currentLevel = logLevel;
}

void Log::info(const char *msg)
{
  if (m_currentLevel > Level::logInfo)
    return;
  std::cout << "\033[34m"
            << "[Info]: " << msg << "\033[37m \n";
}

void Log::warn(const char *msg)
{
  if (m_currentLevel > Level::logWarn)
    return;
  std::cout << "\033[1m\033[33m"
            << "[Warning]: " << msg << "\033[37m \n";
}

void Log::error(const char *msg, int statusCode)
{
  if (m_currentLevel > Level::logError)
    return;
  std::cout << "\033[1m\033[31m"
            << "[Error]: " << msg << "\033[37m \n";
  exit(statusCode);
}