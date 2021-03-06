//
//  BasicLibString.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__BasicLibString__
#define __SoLibs__BasicLibString__

#include <iostream>
#include <string>
#include <sstream>
#include "BasicLibTypes.h"

namespace BasicLib {
    // ============================================================
    // These functions get a time value. The Actual meaning of this
    // time is undefined; it is only meant to be relative.
    // ============================================================
    std::string UpperCase( const std::string& p_string );
    std::string LowerCase( const std::string& p_string );
    
    
    std::string SearchAndReplace(
                                 const std::string& p_target,
                                 const std::string& p_search,
                                 const std::string& p_replace );
    
    
    const std::string WHITESPACE = " \t\n\r";
    
    std::string TrimWhitespace( const std::string& p_string );
    std::string ParseWord( const std::string& p_string, int p_index );
    std::string RemoveWord( const std::string& p_string, int p_index );
    
    
    
    
    
    // ============================================================
    //  Stream Insertion and Extraction functions
    // ============================================================
    
    
    template< typename type >
    inline void insert( std::ostream& s, const type& t )  {  s << t; }
    template< typename type >
    inline type& extract( std::istream& s, type& t )  {  s >> t; return t; }

    template< typename type >
    inline std::string tostring( const type& p_type, size_t p_width = 0 )
    {
        std::stringstream str;
        insert( str, p_type );
        
        // if string is larger than width, just return the whole thing.
        if( str.str().size() >= p_width )
            return str.str();
        
        // add as many spaces as needed after the string if not.
        return str.str() + std::string( p_width - str.str().size(), ' ' );
    }
    
    template< typename type >
    inline type totype( const std::string& p_string )
    {
        std::stringstream str( p_string );
        type t;
        extract( str, t );
        return t;
    }

    
}

#endif /* defined(__SoLibs__BasicLibString__) */
