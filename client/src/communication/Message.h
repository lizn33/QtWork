//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_MESSAGE_H
#define QTWORK_MESSAGE_H
#include <QObject>
#include <QTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <optional>

enum class MessageType {
    PlainText,
    RequestFriend,
    ApproveFriend
};

enum class ChatType {
    User,
    Group
};

enum class MessageStatus {
    Ack,
    UnAck
};

QString ChatTypeToString(ChatType chatType);

ChatType ChatTypeFromString(QString str);

MessageType MessageTypeFromString(QString str);

MessageStatus MessageStatusFromString(QString str);

struct Chat {
    long id;
    ChatType type;
};

class Message {
public:
    static Message PlainTextMessage(Chat chat) {
        Message res;
        res.receiverID = chat.id;
        res.chatType = chat.type;
        res.messageType = MessageType::PlainText;
        return res;
    }

    bool operator < (const Message& other) const {
        return messageID < other.messageID;
    }

    static std::optional<Message> fromJson(QString json) {

        QJsonParseError parseError;
        auto document = QJsonDocument::fromJson(json.toUtf8(), &parseError);
        if (document.isNull() && parseError.error != QJsonParseError::NoError) {
            return {};
        }
        auto object = document.object();
        Message res;
        res.messageID = object.take("id").toInt();
        res.senderID  = object.take("sender_id").toInt();
        res.receiverID = object.take("receiver_id").toInt();
        res.chatType = ChatTypeFromString(object.take("chat_type").toString());

        res.sendTime = QDateTime::fromString(object.take("send_time").toString());
        res.receivedTime = QDateTime::fromString(object.take("received_time").toString());

        res.messageType = MessageTypeFromString(object.take("type").toString());
        res.content = object.take("content").toString();
        res.messageStatus = MessageStatusFromString(object.take("status").toString());
    }

    static const QString USER;
    static const QString GROUP;

private:
    Message(){}
    long messageID;
    long receiverID;
    long senderID;
    QDateTime sendTime;
    QDateTime receivedTime;
    ChatType chatType;
    MessageType messageType;
    QString content;
    MessageStatus messageStatus;

};

#endif //QTWORK_MESSAGE_H
