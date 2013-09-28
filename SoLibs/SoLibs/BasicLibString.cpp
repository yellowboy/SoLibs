//
//  BasicLibString.cpp
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#include "BasicLibString.h"
#include <cctype>
#include <stdlib.h>

namespace BasicLib {
    std::string UpperCase( const std::string& p_string )
    {
        std::string str = p_string;
        
        for( size_t i = 0; i < str.size(); i++ )
        {
            str[i] = toupper( str[i] );
        }
        return str;
    }
    
}