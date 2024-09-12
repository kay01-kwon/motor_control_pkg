#include "socket_client_impl.hpp"
#include <common_functions.h>

SocketClientImpl::SocketClientImpl()
{
    ip_addr_ = "169.254.225.195";
    port_ = 3000;
}

SocketClientImpl::SocketClientImpl(string ip_addr, int port)
{
    ip_addr_ = ip_addr;
    port_ = port;
}

int SocketClientImpl::create_socket()
{
    // Create a socket

    socket_fd_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if( socket_fd_ < 0)
    {
        // cout << "Socket creation failed" << endl;
        return -1;
    }
    socket_fd_ptr_ = &socket_fd_;
    return 0;
}

int SocketClientImpl::socket_connect()
{

    memset(&server_addr_, 0, sizeof(server_addr_));

    // Set up the protocol
    server_addr_.sin_family = AF_INET;

    // Set the IP address
    server_addr_.sin_addr.s_addr = inet_addr(ip_addr_.c_str());

    // Set the port
    server_addr_.sin_port = htons(port_);

    // Connect to the server
    if(connect(socket_fd_, (struct sockaddr *)&server_addr_, sizeof(server_addr_)) < 0)
    {
        // cout << "Connection failed" << endl;
        return -1;
    }

    // cout << "Connected to server" << endl;

    return 0;
}

int SocketClientImpl::socket_send(uint8_t *data, int data_size)
{

    if(send(socket_fd_, data, data_size, 0) < 0)
    {
        // cout << "Send failed" << endl;
        return -1;
    }

    return 0;
}

int SocketClientImpl::socket_recv(uint8_t *data, int data_size)
{
    if(recv(socket_fd_, data, data_size, 0) < 0)
    {
        // cout << "Receive failed" << endl;
        return -1;
    }

    return 0;
}
