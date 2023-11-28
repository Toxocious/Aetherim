#pragma once

#if defined( _WIN64 ) || defined( _WIN32 )
#    include <Windows.h>
#else
#    include <string.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

class Log
{
  public:
    static void log( const std::string & message )
    {
        std::ofstream logFile( "Aetherim.log", std::ios::app );

        if ( logFile.is_open() )
        {
            std::time_t now = std::time( 0 );
            std::tm * timeinfo = std::localtime( &now );

            char timestamp[20];
            std::strftime( timestamp, sizeof( timestamp ), "%Y-%m-%d %H:%M:%S", timeinfo );

            logFile << "[" << timestamp << "] " << message << std::endl;
            logFile.close();
        }
    }
};
