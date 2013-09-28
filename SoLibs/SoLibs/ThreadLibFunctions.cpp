//
//  ThreadLibFunctions.cpp
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#include "ThreadLibFunctions.h"

namespace ThreadLib {
    
    void* DummyRun( void* p_data ){
        // convert the dummy data
        DummyData* data = (DummyData*)p_data;
        
        // run the function with the given data
        data->m_func( data->m_data );
        
        // now delete the data
        delete data;
        
        // and return 0.
        return 0;
    }
}

