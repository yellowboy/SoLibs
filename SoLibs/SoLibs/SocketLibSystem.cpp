//
//  SocketLibSystem.cpp
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#include "SocketLibSystem.h"
#include "SocketLibErrors.h"

namespace SocketLib {
    // ========================================================================
    // Function:    GetIPAddress
    // Purpose:     To get the IP address of the string as an ipaddress
    //              structure. Throws an exception if the address cannot be
    //              converted.
    // ========================================================================
    ipaddress GetIPAddress( const std::string p_address )
    {
        
        if( IsIPAddress( p_address ) )
        {
            // if the address is just a regular IP address, there's no need
            // to do a DNS lookup, so just convert the string directly into
            // its binary format.
            ipaddress addr = inet_addr( p_address.c_str() );
            
            // if the address is invalid, throw a HOST_NOT_FOUND exception.
            if( addr == INADDR_NONE )
            {
                throw Exception( EDNSNotFound );
            }
            
            // by this point, the address is valid, so return it.
            return addr;
        }
        else
        {
            // the address isn't an IP address, so we need to look it up using
            // DNS.
            struct hostent* host = gethostbyname( p_address.c_str() );
            
            // if there was an error, throw an exception.
            if( host == 0 )
            {
                // get the error from h_errno.
                throw Exception( GetError( false ) );
            }
            
            // now perform some really wierd casting tricks to get the value.
            // h_addr is a char*, so cast it into an ipaddress*, and
            // dereference it to get the value.
            return *((ipaddress*)host->h_addr);
        }
    }

    // ========================================================================
    // Function:    GetIPString
    // Purpose:     Converts an ipaddress structure to a string in numerical
    //              format.
    // ========================================================================
    std::string GetIPString( ipaddress p_address )
    {
        // return a new string containing the address.
        // (god that is some ugly casting going on... stupid language)
        char* str = inet_ntoa( *((in_addr*)&p_address) );
        if( str == 0 )
        {
            return std::string( "Invalid IP Address" );
        }
        return std::string( str );
    }
    // ========================================================================
    // Function:    GetHostNameString
    // Purpose:     Converts an ipaddress structure to a string using
    //              reverse-DNS lookup. This may block.
    // ========================================================================
    std::string GetHostNameString( ipaddress p_address )
    {
        // get the host info.
        struct hostent* host = gethostbyaddr( (char*)&p_address, 4, AF_INET );
        
        // if there was an error, throw an exception.
        if( host == 0 )
        {
            // get the error from h_errno.
            throw Exception( GetError( false ) );
        }
        
        return std::string( host->h_name );
    }
    
    // ========================================================================
    // Function:    IsIPAddress
    // Purpose:     determines if a string contains a pure numerical IP address
    //              (returns true) or a DNS'able address (returns false)
    // ========================================================================
    bool IsIPAddress( const std::string p_address )
    {
        // scan through the string to see if it's a pure IP address or not.
        // basically, we assume that any string with characters other than
        // numerics and periods needs to be DNS'ed.
        for( size_t i = 0; i < p_address.length(); i++ )
        {
            if( ( p_address[i] < '0' || p_address[i] > '9' ) &&
               p_address[i] != '.' )
                return false;
        }
        return true;
    }


}
