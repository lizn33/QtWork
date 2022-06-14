-- Chat是个抽象类
-- User Group继承它
CREATE TABLE chat (
    id INTEGER PRIMARY KEY ,
    chat_type TEXT CHECK ( chat_type IN ('User, Group'))
);

-- User 信息
CREATE TABLE user (
    id INTEGER PRIMARY KEY ,
    name VARCHAR(20),
    password VARCHAR(20),
    last_received_message_id INTEGER, -- 最后一次收到的message用于，查询离线消息
    FOREIGN KEY (id) REFERENCES chat(id),
    FOREIGN KEY (last_received_message_id) REFERENCES message(id)
);

-- Chat 信息
CREATE TABLE group_chat (
    id INTEGER PRIMARY KEY,
    name VARCHAR(20),
    FOREIGN KEY (id) REFERENCES chat(id)
);

-- 群成员
CREATE TABLE group_member (
    group_id INTEGER,
    user_id INTEGER,
    FOREIGN KEY (group_id) REFERENCES group_chat(id),
    FOREIGN KEY (user_id) REFERENCES user(id),
    PRIMARY KEY (group_id, user_id)
);

-- 消息存储
CREATE TABLE message(
    id INTEGER PRIMARY KEY,
    message_from INTEGER, -- 发送者
    message_to INTEGER,   -- 接受者
    message_type TEXT,    -- 消息类型
    content TEXT,         -- 内容
    FOREIGN KEY (message_from) REFERENCES user(id),
    FOREIGN KEY (message_to) REFERENCES  chat(id)
);
