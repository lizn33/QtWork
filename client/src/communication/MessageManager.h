//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_MESSAGEMANAGER_H
#define QTWORK_MESSAGEMANAGER_H
#include <QtWebSockets/QtWebSockets>
#include <QWidget>
#include <QObject>
#include <QtCore>
#include <QMutex>
#include <QQueue>
#include <queue>
#include <optional>
#include <set>
#include <QThread>
#include <QWebSocket>
#include <iostream>

#include "Message.h"
#include "entity/UserInfo.h"


class MessageManager: public QObject {
    Q_OBJECT

public:
    MessageManager() {

        connect(&qWebSocket, &QWebSocket::textMessageReceived,this, [this] (QString messageText) {
            auto message = Message::fromJson(messageText);

            qDebug() << messageText << '\n';
            if (message.has_value()) {
                pushMessage(std::move(*message));
            }
        });
    }

    std::optional<Message> popMessage() {
        if (messages.empty()) {
            return {};
        }
        auto res = *messages.begin();
        messages.erase(messages.begin());
        return res;
    }

    void pushMessage(Message message) {
        messages.insert(message);
        emit receivedMessage();
    }

    void connectToServer() {
        QString url = "ws://localhost/connect/" + UserInfo::getInstance().getID();
        qWebSocket.open(QUrl(url));
    }

    void ackMessage(long messageId) {
        qWebSocket.sendTextMessage(QString::number(messageId));
    }


signals:
    void receivedMessage();
private:
    QThread qThread;
    QWebSocket qWebSocket;
    std::set<Message> messages;
};


#endif //QTWORK_MESSAGEMANAGER_H
