//
//  BasicLibTime.cpp
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#include "BasicLibTime.h"
#include <time.h>
#include <sys/time.h>
#include "BasicLibString.h"

namespace BasicLib {
    // ============================================================
    // These functions get a time value. The Actual meaning of this
    // time is undefined; it is only meant to be relative.
    // ============================================================
    sint64 GetTimeMS()
    {

        struct timeval t;
        sint64 s;
        
        // get the time of day
        gettimeofday( &t, 0 );
        
        // calculate the number of milliseconds represented by the seconds
        s = t.tv_sec;
        s *= 1000;
        
        // calculate the milliseconds now
        s += (t.tv_usec / 1000);
        
        // return the value
        return s;
    }
    
    
    sint64 GetTimeS()
    {
        return GetTimeMS() / 1000;
    }
    
    sint64 GetTimeM()
    {
        return GetTimeMS() / 60000;
    }
    
    sint64 GetTimeH()
    {
        return GetTimeMS() / 3600000;
    }
    
    // ============================================================
    // This prints a timestamp in 24 hours hh:mm:ss format
    // ============================================================
    std::string TimeStamp()
    {
        char str[9];
        
        // get the time, and convert it to struct tm format
        time_t a = time(0);
        struct tm* b = localtime( &a );
        
        // print the time to the string
        strftime( str, 9, "%H:%M:%S", b );
        
        return str;
    }
    
    
    // ============================================================
    // This prints a datestamp in YYYY:MM:DD format
    // ============================================================
    std::string DateStamp()
    {
        char str[11];
        
        // get the time, and convert it to struct tm format
        time_t a = time(0);
        struct tm* b = localtime( &a );
        
        // print the time to the string
        strftime( str, 11, "%Y.%m.%d", b );
        
        return str;
    }
    
    
    Timer::Timer()
    {
        m_starttime = 0;
        m_inittime = 0;
    }
    
    
    void Timer::Reset( sint64 p_timepassed )
    {
        m_starttime = p_timepassed;
        m_inittime = GetTimeMS();
    }
    
    sint64 Timer::GetMS()
    {
        // return the amount of time that has elapsed since the timer
        // was initialized, plus whatever starting time the timer was given.
        return (GetTimeMS() - m_inittime) + m_starttime;
    }
    
    sint64 Timer::GetS()
    {
        return GetMS() / 1000;
    }
    
    sint64 Timer::GetM()
    {
        return GetMS() / 60000;
    }
    
    sint64 Timer::GetH()
    {
        return GetMS() / 3600000;
    }
    
    sint64 Timer::GetD()
    {
        return GetMS() / 86400000;
    }
    
    sint64 Timer::GetY()
    {
        return GetD() / 365;
    }
    
    std::string Timer::GetString()
    {
        std::string str;
        sint64 y = GetY();
        sint64 d = GetD() % 365;
        sint64 h = GetH() % 24;
        sint64 m = GetM() % 60;
        
        if( y > 0 )
            str += BasicLib::tostring( y ) + " years, ";
        if( d > 0 )
            str += BasicLib::tostring( d ) + " days, ";
        if( h > 0 )
            str += BasicLib::tostring( h ) + " hours, ";
        
        str += BasicLib::tostring( m ) + " minutes";
        
        return str;
    }

    
}