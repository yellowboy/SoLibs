//
//  SocketSet.h
//  SoLibs
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __SoLibs__SocketSet__
#define __SoLibs__SocketSet__

#include <iostream>
#include "SocketLibTypes.h"
#include "SocketLibSocket.h"
#include <set>

namespace SocketLib {
    const int MAX = FD_SETSIZE;
    
    class SocketSet{
    public:
        SocketSet();
        void AddSocket( const Socket& p_sock );
        void RemoveSocket( const Socket& p_sock );
        
        inline int Poll( int p_time = 0 )
        {
            // this is the time value structure. It will determine how long
            // the select function will wait.
            struct timeval t = { 0, p_time * 1000 };
            //struct timeval t = { 0, 0 };//long-p_time
            
            // copy the set over into the activity set.
            m_activityset = m_set;
            // now run select() on the sockets.
            if( m_socketdescs.size() == 0 ) return 0;
            return select( *(m_socketdescs.rbegin()), &m_activityset, 0, 0, &t );
        }
        
        inline bool HasActivity( const Socket& p_sock )
        {
            return FD_ISSET( p_sock.GetSock(), &m_activityset ) != 0;
        }

    protected:
        // a set representing the socket descriptors.
        fd_set m_set;
        
        // this set will represent all the sockets that have activity on them.
        fd_set m_activityset;
        
        // this is only used for linux, since select() requires the largest
        // descriptor +1 passed into it. BLAH!
        std::set<sock> m_socketdescs;

    };
    
}

#endif /* defined(__SoLibs__SocketSet__) */
