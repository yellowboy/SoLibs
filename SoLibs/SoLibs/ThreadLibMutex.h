//
//  ThreadLibMutex.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__ThreadLibMutex__
#define __SoLibs__ThreadLibMutex__

#include <iostream>
#include <pthread.h>
#include <string>

namespace ThreadLib {
    class Mutex{
    public:
        // ====================================================================
        // Description: Initialize the mutex object
        // ====================================================================
        Mutex()
        {
            pthread_mutex_init( &m_mutex, 0 );

        }
        // ====================================================================
        // Description: Destroy the mutex object
        // ====================================================================
        ~Mutex()
        {

            pthread_mutex_destroy( &m_mutex );

        }
        
        // ====================================================================
        // Description: Wait for a lock, then hold the lock
        // ====================================================================
        inline void Lock()
        {
            pthread_mutex_lock( &m_mutex );

        }
        
        // ====================================================================
        // Description: release the lock
        // ====================================================================
        inline void Unlock()
        {
            pthread_mutex_unlock( &m_mutex );
        }

    protected:
        pthread_mutex_t m_mutex;
    };
}

#endif /* defined(__SoLibs__ThreadLibMutex__) */
