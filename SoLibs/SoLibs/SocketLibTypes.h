//
//  SocketLibTypes.h
//  Mud001
//
//  Created by Andrew on 13-9-28.
//  Copyright (c) 2013年 Andrew. All rights reserved.
//

#ifndef __Mud001__SocketLibTypes__
#define __Mud001__SocketLibTypes__

#include <iostream>
#include <sys/types.h>      // header containing all basic data types and
// typedefs
#include <sys/socket.h>     // header containing socket data types and
// functions
#include <netinet/in.h>     // IPv4 and IPv6 stuff
#include <unistd.h>         // for gethostname()
#include <netdb.h>          // for DNS - gethostbyname()
#include <arpa/inet.h>      // contains all inet_* functions
#include <errno.h>          // contains the error functions
#include <fcntl.h>          // file control
namespace SocketLib {
    typedef int sock;
    // ========================================================================
    //  Ports will be in host byte order, but IP addresses in network byte
    //  order. It's easier this way; ports are usually accessed as numbers,
    //  but IP addresses are better accessed through the string functions.
    // ========================================================================
    typedef unsigned short int port;        // define the port type.
    typedef unsigned long int ipaddress;    // an IP address for IPv4
}

#endif /* defined(__Mud001__SocketLibTypes__) */
