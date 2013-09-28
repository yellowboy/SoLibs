//
//  BasicLibTime.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__BasicLibTime__
#define __SoLibs__BasicLibTime__

#include <iostream>
#include "BasicLibTypes.h"
#include <string>

namespace BasicLib {
    // ============================================================
    // These functions get a time value. The Actual meaning of this
    // time is undefined; it is only meant to be relative.
    // ============================================================
    sint64 GetTimeMS();
    sint64 GetTimeS();
    sint64 GetTimeM();
    sint64 GetTimeH();
    
    // ============================================================
    // This prints a timestamp in 24 hours hh:mm:ss format
    // ============================================================
    std::string TimeStamp();
    
    
    // ============================================================
    // This prints a datestamp in YYYY:MM:DD format
    // ============================================================
    std::string DateStamp();
    
    // ============================================================
    //  The Timer Class
    // ============================================================
    class Timer
    {
    public:
        
        Timer();
        
        void Reset( sint64 p_timepassed = 0 );
        
        sint64 GetMS();
        sint64 GetS();
        sint64 GetM();
        sint64 GetH();
        sint64 GetD();
        sint64 GetY();
        
        std::string GetString();
        
        
        
    protected:
        
        // this is the system time at which the timer was initialized
        sint64 m_inittime;
        
        // this is the official "starting time" of the timer.
        sint64 m_starttime;
    };
    
    inline sint64 seconds( sint64 t )   { return t * 1000; }
    inline sint64 minutes( sint64 t )   { return t * 60 * 1000; }
    inline sint64 hours( sint64 t )     { return t * 60 * 60 * 1000; }
    inline sint64 days( sint64 t )      { return t * 24 * 60 * 60 * 1000; }
    inline sint64 weeks( sint64 t )     { return t * 7 * 24 * 60 * 60 * 1000; }
    inline sint64 years( sint64 t )     { return t * 365 * 24 * 60 * 60 * 1000; }
}
#endif /* defined(__SoLibs__BasicLibTime__) */
