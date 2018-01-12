#include "TcpServ.h"

tcpServ::tcpServ(){
    mport=5001;
    //TCP 
    socket_fd=socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd){
    }
        
}

bool tcpServ::init(){
    socket_fd=socket(AF_INET,SOCK_STREAM,0);
    if(socket_fd<0){
        return false;
    }
    //设置非阻塞
    lang opts=fcntl(socket_fd,F_GETFL,0);
    if(fcntl(socket_fd,F_SETFL,opts|O_NONBLOCK)<0){
        return false;
    }
    
    return true;
}

int tcpServ:indSock(){
    saddr.sin_family=AF_INET;
    saddr.sin_port=htons(mport);
    //多网卡同时绑定
    saddr.sin_addr.s_addr=htonl(INADDR_ANY);
    //单网卡
    //saddr.sin_addr.s_addr=inet_addr("192.168.1.60");
    //inet_ntoa 相反 inet_addr
    return bind(socket_fd,(struct sockaddr*)&saddr,sizeof(saddr));
}

int tcpServ::listenSock(){
    retrun listen(socket_fd,LISTENBACKLOG);
}

void tcpServ::acceptSock(){
    int connfd;
    sockaddr_in cliaddr;
    while(1){
        connfd=accetp(socket_fd,(struct cliaddr*)&cliaddr,sizeof(cliaddr));
    }
}

tcpServ::~tcpServ(){
    close(socket_fd);
}
