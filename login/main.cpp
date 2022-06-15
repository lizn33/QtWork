#include <iostream>
#include <string>
#include <assert.h>

#include "server.h"

using namespace std;

int main(int argc, char *argv[])
{
    string grpc_recv_ip = "0.0.0.0";
    uint16_t grpc_port = 6379;
    string redis_ip = "127.0.0.1";
    uint16_t redis_port = 5000;
	run(grpc_recv_ip, grpc_port, redis_ip, redis_port);
    return 0;
}