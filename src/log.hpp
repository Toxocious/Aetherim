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
#include <chrono>

enum class LogLevel
{
    INFO,
    WARN,
    ERROR,
    FATAL
};

class Log
{
  private:
    bool save_to_file;
    bool console_output;

    std::ofstream file;

    LogLevel priority_level;

    void Message( LogLevel log_level, const std::string & message );

  public:
    Log( std::string log_file_path = "Aetherim.log" );

    void Fatal( const std::string & message );
    void Error( const std::string & message );
    void Warn( const std::string & message );
    void Info( const std::string & message );
};

Log::Log( std::string log_file_path )
{
    if ( log_file_path.empty() )
    {
        if ( !console_output )
        {
            throw std::invalid_argument( "Log file path it not set." );
        }

        this->save_to_file = false;
    }
    else
    {
        this->file.open( log_file_path, std::ios_base::app );
        if ( !this->file )
        {
            throw std::runtime_error( "Failed to open file at " + log_file_path + "." );
        }
        else
        {
            this->save_to_file = true;
        }
    }

    this->console_output = console_output;
}

void Log::Message( LogLevel log_level, const std::string & message )
{
    char timestamp[64];
    auto now = std::chrono::system_clock::now();
    std::time_t cnow = std::chrono::system_clock::to_time_t( now );
    std::strftime( timestamp, sizeof( timestamp ), "%b. %d, %Y @ %I:%M %p", std::localtime( &cnow ) );

    std::string log_text = "[" + static_cast<std::string>( timestamp ) + "]";

    switch ( log_level )
    {
        case LogLevel::FATAL:
            log_text += " [FATAL] ";
            break;

        case LogLevel::ERROR:
            log_text += " [ERROR] ";
            break;

        case LogLevel::WARN:
            log_text += " [WARN ] ";
            break;

        case LogLevel::INFO:
            log_text += " [INFO ] ";
            break;

        default:
            log_text += " [INFO ] ";
            break;
    }

    log_text += message + "\n";

    file << log_text;
    file.close();
}

void Log::Fatal( const std::string & message ) { Message( LogLevel::FATAL, message ); }

void Log::Error( const std::string & message ) { Message( LogLevel::ERROR, message ); }

void Log::Warn( const std::string & message ) { Message( LogLevel::WARN, message ); }

void Log::Info( const std::string & message ) { Message( LogLevel::INFO, message ); }
