//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_FRIEND_H
#define QTWORK_FRIEND_H

#include <QString>
#include <QJsonObject>
#include <QJsonDocument>
#include <qjsonobject.h>

class Friend {
    Friend(long ID, QString friendName)
    : Id(ID)
    , name(friendName) {}

public:
    long getID() const {
        return Id;
    }
    QString getName() const {
        return name;
    }

private:
    long Id;
    QString name;
};

#endif //QTWORK_FRIEND_H
