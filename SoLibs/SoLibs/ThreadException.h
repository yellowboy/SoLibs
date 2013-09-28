//
//  ThreadException.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__ThreadException__
#define __SoLibs__ThreadException__

#include <iostream>
#include <exception>
#include <pthread.h>

namespace ThreadLib {
    enum Error
    {
        Unspecified,                // unspecified error
        InitFailure,                // thread library not initialized
        CreationFailure             // thread cannot be created
    };
    
    
    class Exception : public std::exception
    {
    public:
        // ====================================================================
        // Description: set the error code of the exception, with a default of
        //              Unspecified.
        // ====================================================================
        Exception( Error p_error = Unspecified )
        {
            m_error = p_error;
        }
        
        // ====================================================================
        // Description: Gets the error code of the exception
        // ====================================================================
        Error GetError() const
        {
            return m_error;
        }
        
    protected:
        Error m_error;
    };
}

#endif /* defined(__SoLibs__ThreadException__) */
