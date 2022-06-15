# QtWork



## 消息

#### 消息类型

RequireAddFriend

ResponseAddFriend 



PlainText





## 前后端接口

1.登录 POST

/login/{id}  application/x-www-form-urlencoded password="password"

成功 {"result": "success"}

失败{"result": "fail", "reason":  用户不存在/密码错误}



2.注册 POST

/register           application/ name=""&password=""



3.退出登录，此时只能收到离线消息 GET

/logout/{id}



4.发送消息  POST

/send-message/{from_id}/{to_id}



5.删除好友 GET

/delete-friend/{a-id}/{b-id}



6.获取好友列表

/get-friends/{id}



7.获取群列表

/get-group/{id}



8.加入群 GET

/join-group/{user-id}/{group-id}



9.退群 GET

/leave-group/{user-id}/{group-id}




-----------c++登录验证用户名和密码部分---------------------------------

客户端只需配置好grpc环境后，编译部署login/grpc_cli目录下的文件即可

客户端login类下的Account函数
int login::Account(string user, string passwd)函数

返回值为uint32_t类型
含义: 0:正确; 1:密码错误; 2:无该账号; 3:其他错误(可能为redis无连接)
























