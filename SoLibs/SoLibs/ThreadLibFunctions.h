//
//  ThreadLibFunctions.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__ThreadLibFunctions__
#define __SoLibs__ThreadLibFunctions__

#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include "ThreadException.h"

namespace ThreadLib {
    typedef void (*ThreadFunc)(void*);
    
    class DummyData{
    public:
        ThreadFunc m_func;
        void* m_data;
    };
    
    void* DummyRun( void* p_data );
    
    inline pthread_t Create( ThreadFunc p_func, void* p_param ){
        pthread_t t;
        DummyData* data = new DummyData;
        data->m_func = p_func;
        data->m_data = p_param;
        pthread_create( &t, 0, DummyRun, data );
        if (t == 0) {
            delete data;
            throw Exception(CreationFailure);
        }
        return t;
    }
    
    inline pthread_t GetID(){
        return pthread_self();
    }
    
    inline void WaitForFinish( pthread_t p_thread ){
        pthread_join( p_thread, NULL );
    }
    
    inline void Kill( pthread_t& p_thread ){
        pthread_cancel( p_thread );
    }
    
    inline void YieldThread( int p_milliseconds = 1 ){
        usleep( p_milliseconds * 1000 );
    }
}

#endif /* defined(__SoLibs__ThreadLibFunctions__) */
