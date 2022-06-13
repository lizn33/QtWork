#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

using namespace std;

int main()
{
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0)
    {
        std::cout << "listenfd error" << std::endl;
        exit(0);
    }

    sockaddr_in serve_addr, client_addr;

    serve_addr.sin_family = AF_INET;
    serve_addr.sin_addr.s_addr = htonl(INADDR_ANY);//inet_addr("172.25.63.8");//
    serve_addr.sin_port = htons(6379);
    int opt = 1;
    if(setsockopt(listenfd, SOL_SOCKET,SO_REUSEADDR, (const void *)&opt, sizeof(opt)))
    {
		cout << "setsockopt error" << endl;
		exit(0);
    }
    
    if(bind(listenfd, (sockaddr*)&serve_addr, sizeof(serve_addr)))
    {
        cout << "bind error" << endl;
        exit(0);
    }
    
    
    std::cout << "listen..." << std::endl;
    if(listen(listenfd, 10))
    {
        cout << "listen error" << endl;
        exit(0);
    }

    std::cout << "wait accept..." << std::endl;
    int addr_len = sizeof(client_addr);
    int clientfd = accept(listenfd, (sockaddr*)&client_addr, (socklen_t*) &addr_len);
    
    std::cout << "accept access " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << std::endl;

    char buff[1024];
    while(1)
    {
        std::cout << "wait recv..." << std::endl;
        recv(clientfd, buff, 1024, 0);

        std::cout << buff << std::endl;
        std::cin >> buff;
        send(clientfd, buff, 1024, 0);

        break;
    }
    return 0;
}