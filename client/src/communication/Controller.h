//
// Created by ccx on 22-6-16.
//

#ifndef QTWORK_CONTROLLER_H
#define QTWORK_CONTROLLER_H
#include <QObject>
#include <QNetworkAccessManager>


class Controller: public QObject {
    Q_OBJECT
public:
    void sendAddFriend() {

    }

    void getFriendsAndGroups() {


    }



private:

public slots:

private:
    QNetworkAccessManager  manager;
};


#endif //QTWORK_CONTROLLER_H
