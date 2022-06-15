#include <cli_login.h>

using namespace std;

int main(int argc, char *argv[])
{
    std::string address("0.0.0.0:6379");
    login client(
            grpc::CreateChannel(
                    address,
                    grpc::InsecureChannelCredentials()
            )
    );
    int err;

    string user = "lzn";
    string passwd = "123";

    err = client.Account(user, passwd);

    std::cout << "end :" << err << std::endl;
    return 0;
}