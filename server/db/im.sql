
-- 用户信息
CREATE TABLE users (
    id INTEGER PRIMARY KEY ,
    name VARCHAR(20),
    password VARCHAR(20),
    last_received_message_id INTEGER, -- 最后一次收到的message用于，查询离线消息
    FOREIGN KEY (last_received_message_id) REFERENCES message(id)
);

-- 好友列表
-- 一次插入两条
-- 删除也是两条
CREATE TABLE friends (
    user_id INTEGER,
    friend_id INTEGER,
    FOREIGN KEY (user_id) REFERENCES users(id),
    FOREIGN KEY (friend_id) REFERENCES users(id),
    PRIMARY KEY (user_id, friend_id)
);

-- 群聊 信息
CREATE TABLE groups (
    id INTEGER PRIMARY KEY,
    name VARCHAR(20)
);

-- 群成员
CREATE TABLE group_member (
    group_id INTEGER,
    user_id INTEGER,
    FOREIGN KEY (group_id) REFERENCES groups(id),
    FOREIGN KEY (user_id) REFERENCES users(id),
    PRIMARY KEY (group_id, user_id)
);

-- 消息存储
CREATE TABLE messages (
    id INTEGER PRIMARY KEY AUTOINCREMENT ,
    sender_id INTEGER, -- 发送者
    receiver_id INTEGER,   -- 接受者
    chart_type TEXT CHECK (chart_type in ('User', 'Group')),
    type TEXT,    -- 消息类型
    content TEXT,         -- 内容
    send_time TEXT,
    received_time TEXT,
    status TEXT CHECK ( status in  ('Received', 'UnReceived')),
    FOREIGN KEY (sender_id) REFERENCES users(id)
);
