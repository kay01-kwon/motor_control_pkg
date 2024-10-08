#ifndef SOCKET_CLIENT_IMPL_HPP
#define SOCKET_CLIENT_IMPL_HPP

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <string>
#include <string.h>

using namespace std;


class SocketClientImpl
{
    public:

    friend class RosMotorControl;
    friend class MotorControl;

    SocketClientImpl();

    SocketClientImpl(string ip_addr, int port);

    int create_socket();

    int socket_connect();

    int socket_send(uint8_t *data, int data_size);

    int socket_recv(uint8_t *data, int data_size);


    private:
    
    int socket_fd_;
    int *socket_fd_ptr_;

    string ip_addr_;

    struct sockaddr_in server_addr_;

    int port_{3000};

};




#endif