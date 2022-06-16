//
// Created by ccx on 22-6-15.
//

#include "Message.h"



const QString Message::USER = "User";
const QString Message::GROUP = "Group";

QString ChatTypeToString(ChatType chatType) {
    switch (chatType) {
        case ChatType::User:
            return "User";
        case ChatType::Group:
            return "Group";
    }
    return "User";
}
ChatType ChatTypeFromString(QString str) {
    if (str == "Group") {
        return ChatType::Group;
    } else {
        return ChatType::User;
    }
}

MessageType MessageTypeFromString(QString str) {
    if (str == "RequestFriend") {
        return MessageType::RequestFriend;
    } else if (str == "ApproveFriend"){
        return MessageType::ApproveFriend;
    } else {
        return MessageType::PlainText;
    }
}
MessageStatus MessageStatusFromString(QString str) {
    if (str == "Ack") {
        return MessageStatus::Ack;
    } else {
        return MessageStatus::UnAck;
    }

}