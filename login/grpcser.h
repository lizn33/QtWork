#ifndef GRPCSER_H
#define GRPCSER_H

#include <grpcpp/grpcpp.h>
#include "grpcProto/grpcProto.grpc.pb.h"

#include <string>
#include <cstring>
#include <iostream>

#include "rediscon.h"
#include "log.h"

class AccountServiceImplementation final : public grpcProto::gRPC::Service 
{
    //一个redis连接
    rediscon redis_con;

    //重载grpc请求函数 
    grpc::Status Account
    (
        grpc::ServerContext* context, 
        const grpcProto::accRequest* request, 
        grpcProto::accReply* reply
    ) override;

public:
    //重设redis的ip和端口
    bool redis_reset(std::string& redis_ip, uint16_t redis_port);
    //查看redis连接是否有效, 有效返回true
    bool rediscon_exist();
    
    //构造/析构函数
    AccountServiceImplementation(std::string& redis_ip, uint16_t redis_port);
    ~AccountServiceImplementation();
};

//调用grpc
void grpc_run
(
    std::string& grpc_recv_ip,
    uint16_t grpc_recv_port,
    std::string& redis_ip,
    uint16_t redis_port
);

#endif