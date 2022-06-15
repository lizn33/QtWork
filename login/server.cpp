#include "server.h"

using std::string;
using std::cerr;
using std::cout;
using std::endl;

void run(std::string& grpc_recv_ip, uint16_t grpc_recv_port, std::string& redis_ip, uint16_t redis_port)
{
    //运行grpc服务，负责验证账号密码
    grpc_run(grpc_recv_ip, grpc_recv_port, redis_ip, redis_port);
    
}