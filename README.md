# QtWork



## 消息

#### 消息类型

RequireAddFriend

ResponseAddFriend 



PlainText





## 前后端接口

登录 POST

/login/{id}  application/x-www-form-urlencoded password="password"

成功 {"result": "success"}

失败{"result": "fail", "reason":  用户不存在/密码错误}



注册 POST

/register           application/ name=""&password=""



退出登录，此时只能收到离线消息 GET

/logout/{id}



发送消息  POST

/send-message/{from_id}/{to_id}



删除好友 GET

/delete-friend/{a-id}/{b-id}



获取好友列表

/get-friends/{id}



获取群列表

/get-group/{id}



加入群 GET

/join-group/{user-id}/{group-id}



退群 GET

/leave-group/{user-id}/{group-id}


























