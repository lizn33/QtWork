#ifndef CLI_LOGIN_H
#define CLI_LOGIN_H

#include <string>
#include <iostream>

#include <grpcpp/grpcpp.h>
#include <memory>
#include "../grpcProto/grpcProto.grpc.pb.h"


class login
{
public:
    login(std::shared_ptr<grpc::Channel> channel) : 
            stub_(grpcProto::gRPC::NewStub(channel)) {}

    uint32_t Account(std::string user, std::string passwd);
            
private:
    std::unique_ptr<grpcProto::gRPC::Stub> stub_;
};

#endif