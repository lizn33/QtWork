#include "cli_login.h"

using namespace std;
//using namespace grpcProto;

uint32_t login::Account(std::string user, std::string passwd)
{
    std::unique_ptr<grpcProto::accRequest> p_request(new grpcProto::accRequest);

    p_request->set_user(user);
    p_request->set_passwd(passwd);
    
    std::unique_ptr<grpcProto::accReply> p_reply(new grpcProto::accReply);
    std::unique_ptr<grpc::ClientContext> p_context(new grpc::ClientContext);

    std::unique_ptr<grpc::Status> p_status(new grpc::Status(stub_->Account(p_context.get(), *p_request, p_reply.get())));
    
    if(!p_status->ok())
    {
        std::cout << p_status->error_code() << ":" << p_status->error_message() << std::endl;
        return -1;
    }

    return p_reply->error_num();
}