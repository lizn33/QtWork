#ifndef REDISCON_H
#define REDISCON_H

#include <hiredis/hiredis.h>
#include <string>
#include <memory>

#include "log.h"

class rediscon
{
public:
    //连接redis数据库, 成功返回true
    bool connect(std::string& ip, uint16_t port);

    //查看redis连接是否有效， 有效返回true
    bool con_exist();

    //reply返回类型, 声明为public
    using uqPtr_reply = std::unique_ptr<redisReply, decltype(freeReplyObject)*>;
    //执行redis命令函数
    uqPtr_reply get_reply(std::string command);
    
    //构造函数
    rediscon();
    rediscon(std::string& ip, uint16_t port);
    rediscon(const rediscon& right);
    rediscon(rediscon&& right);

    //析构函数
    ~rediscon();

private:
    std::unique_ptr<redisContext, decltype(redisFree)*> _uq_redis_con;
};

#endif