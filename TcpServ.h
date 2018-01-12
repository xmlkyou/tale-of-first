#ifndef __TCPSERV_H__
#define __TCPSERV_H__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <netdb.h>
#include <sys/epoll.h>

#define LISTENBACKLOG 5

class tcpServ{
    private:
        int socket_fd;
        sockaddr_in saddr;
        char ipstr[16];    
        unsigned int mport;
    public:
        tcpServ();
        bool init();
        int bindSock();
        int listenSock();
        void acceptSock();
        ~tcpServ();
    
};

#endif



