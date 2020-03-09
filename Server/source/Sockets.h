#pragma once
#include <switch.h>
#include <string>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "Results.h"

#define TITLE_MAGIC 0xffaadd23
#define PORT 0xCAFE

struct titlepacket
{
    u32 magic;
    u64 tid;
    char name[512];
};

int sendData(int sock, u64 tid, std::string name);
int setupSocketServer();
