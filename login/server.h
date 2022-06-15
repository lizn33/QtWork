#ifndef SERVER_H
#define SERVER_H

#include <string>
#include <iostream>

#include "rediscon.h"
#include "grpcser.h"

//运行服务
void run
(
    std::string& grpc_recv_ip,
    uint16_t grpc_recv_port,
    std::string& redis_ip,
    uint16_t redis_port
);

#endif