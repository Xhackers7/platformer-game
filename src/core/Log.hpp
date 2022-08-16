#pragma once

#include <iostream>


    class Log
    {
    public:
        enum Level
        {
            logInfo,
            logWarn,
            logError
        };
    
    private:
        static Level m_currentLevel;

    public:
        Log()=delete;

        static void setLevel(Level logLevel);
        static void info(const char *msg);
        static void warn(const char *msg);
        static void error(const char *msg, int statusCode);
    };
