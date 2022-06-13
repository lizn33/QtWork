#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    int servefd = socket(AF_INET, SOCK_STREAM, 0);
    if(servefd < 0)
    {
        std::cout << "listenfd error" << std::endl;
        exit(0);
    }

    sockaddr_in serve_addr, client_addr;
    int addr_len = sizeof(serve_addr);
    serve_addr.sin_family = AF_INET;
    if(argc < 1)
    {
        cout << "default port 8889" << endl;
        serve_addr.sin_port = htons(8889);
    }
    else
    {
        cout << atoi(argv[1]) << endl;
        serve_addr.sin_port = htons(atoi(argv[1]));
    }
    serve_addr.sin_addr.s_addr = inet_addr("27.225.89.60");

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(6380);
    client_addr.sin_addr.s_addr = inet_addr("172.25.63.8");
    int opt = 1;
    if(setsockopt(servefd, SOL_SOCKET,SO_REUSEADDR, (const void *)&opt, sizeof(opt)))
    {
		cout << "setsockopt error" << endl;
		exit(0);
    }

    if(bind(servefd, (sockaddr*)&client_addr, addr_len))
    {
        std::cout << "bind fail: "<< errno << std::endl;
        exit(0);
    }

    std::cout << "wait connect..." << std::endl;
    if(connect(servefd, (sockaddr*)&serve_addr, sizeof(serve_addr)) < 0)
    {
        std::cout << "connect fail: "<< errno << std::endl;
        exit(0);
    }
    std::cout << "connect successed" << std::endl;

    char buff[1024];
    while(true)
    {
        std::cin >> buff;
        int flag = send(servefd, buff, 1024, 0);
        std::cout << "send flag" << flag << std::endl;

        std::cout << "wait recv..." << std::endl;
        flag = recv(servefd, buff, 1024, 0);
        std::cout << "recv flag" << flag << std::endl;
        std::cout << buff << std::endl;

        break;
    }
    return 0;
}