//
//
//
//
#include "packet.h"
#include "listen_handler.h"
int ListenHandler::OnReceived(Packet* packet)
{
    char* data = packet->data();
    uint32_t length = packet->data_length();
    data[length] = '\n';
    printf("received: %s, length:%d\n", data, length);
    return 0;
}
int ListenHandler::OnAccepted(int fd)
{
    printf("accepted fd :%d\n", fd);
    return 0;
}
int ListenHandler::OnSent(Packet* packet)
{
    char* data = packet->data();
    uint32_t length = packet->data_length();
    data[length] = '\n';
    printf("sent: %s\n", data);
    return 0;
}
int ListenHandler::OnTimeOut()
{
    return 0;
}
