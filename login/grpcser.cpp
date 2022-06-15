#include "grpcser.h"

using grpcProto::gRPC;
using grpcProto::accReply;
using grpcProto::accRequest;

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using std::string;

AccountServiceImplementation::AccountServiceImplementation(string& redis_ip, uint16_t redis_port):
    redis_con(redis_ip, redis_port){}

AccountServiceImplementation::~AccountServiceImplementation(){}

//error_num含义: 0:正确; 1:密码错误; 2:无该账号; 3:其他错误(可能为redis无连接)
Status AccountServiceImplementation::Account(ServerContext* context, const accRequest* request, accReply* reply)
{
    string recv_user = request->user();
    string recv_passwd = request->passwd();

    uint32_t error_num = 0;

    //查询该用户名及其对应的密码
    string redis_request = "HGET account " + recv_user;
    rediscon::uqPtr_reply redis_reply = redis_con.get_reply(move(redis_request));//右值可避免重新分配内存
    
    //判断用户是否存在及密码是否正确
    switch(redis_reply->type)
    {
    case 1:
    {
        if(!std::strcmp(redis_reply->str, recv_passwd.c_str()))
            error_num = 0;
        else
            error_num = 1;
        break;
    }
    case 4:
    {
        error_num = 2;
        break;
    }
    default:
    {
        error_num = 3;
        break;
    }
    }
    reply->set_error_num(error_num);
    return Status::OK;
}

bool AccountServiceImplementation::redis_reset(std::string& redis_ip, uint16_t redis_port)
{
    return redis_con.connect(redis_ip, redis_port);
}

bool AccountServiceImplementation::rediscon_exist()
{
    return redis_con.con_exist();
}

void grpc_run(std::string& grpc_recv_ip, uint16_t grpc_recv_port, std::string& redis_ip, uint16_t redis_port)
{
    std::string address = grpc_recv_ip + ":" + std::to_string(grpc_recv_port);

    std::unique_ptr<AccountServiceImplementation> p_service(new AccountServiceImplementation(redis_ip, redis_port));
    if(!p_service->rediscon_exist())
    {
        log("redis_con error");
        exit(0);
    }

    std::unique_ptr<ServerBuilder> p_builder(new ServerBuilder);

    p_builder->AddListeningPort(address, grpc::InsecureServerCredentials());
    p_builder->RegisterService(p_service.get());

    std::unique_ptr<Server> server(p_builder->BuildAndStart());

    log("Server listening on port: " + address);

    //阻塞
    server->Wait();
}