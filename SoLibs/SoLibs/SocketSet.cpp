//
//  SocketSet.cpp
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#include "SocketSet.h"
#include <algorithm>

namespace SocketLib {
    SocketSet::SocketSet()
    {
        FD_ZERO( &m_set );
        FD_ZERO( &m_activityset );
    }
    
    void SocketSet::AddSocket( const Socket& p_sock )
    {
        // add the socket desc to the set
        FD_SET( p_sock.GetSock(), &m_set );
        
        // if linux, then record the descriptor into the vector,
        // and check if it's the largest descriptor.
        m_socketdescs.insert( p_sock.GetSock() );
        
    }
    
    void SocketSet::RemoveSocket( const Socket& p_sock )
    {
        FD_CLR( p_sock.GetSock(), &m_set );
        
        // remove the descriptor from the vector
        m_socketdescs.erase( p_sock.GetSock() );
        
    }
}