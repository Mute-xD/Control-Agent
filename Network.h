//
// Created by Mute on 2022/1/7.
//

#ifndef CLIONTEST_NETWORK_H
#define CLIONTEST_NETWORK_H

#include "stdafx.h"
#include "Status.h"
#include "Threading.h"
#define BUFFER 1024
#define QUEUE 5
#define HEADER_SIZE 6
#define PULSE 1


#define CONTINUE 1
#define OK 2
#define ERROR 0
typedef unsigned char BYTE;


class Network
{
public:
    explicit Network(int port, int index);
    void Connect();
    int sockFD;
    int connectFD;
    void RegistStatus(Status &status1);
    void Send(BYTE* data, int dataLen);
    void Recv();
    void Forward(BYTE* frameData, int dataLen);

    int index;
    bool isDisconnected = false;
private:
    sockaddr_in serverSockAddress{};
    void RecvProcess(BYTE *frameData, int dataLen);
    Status* status = nullptr;
    static void unexpectedPack(BYTE* frameData, int dataLen);

};
void* networkThread(void* data);
struct NetThreadData
{
    int port{};
    Status* status{};
    int index;
};

void netJob(Network net);
void* deamonCheckThread(void* data);
void* deamonSetThread(void* data);
struct DeamonThreadData
{
    Network* net;
    Status* status;
};



#endif //CLIONTEST_NETWORK_H
