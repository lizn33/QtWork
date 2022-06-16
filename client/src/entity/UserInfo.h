//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_USERINFO_H
#define QTWORK_USERINFO_H
#include <QString>

#include "Friend.h"
#include "Group.h"

class UserInfo:QObject {

public:
    static UserInfo& getInstance() {
        static UserInfo userInfo;
        return userInfo;
    }

    bool hasFriend(long friendID) const {
        return std::find_if(friends.cbegin(), friends.cend(), [friendID](const Friend&item) {
            return item.getID() == friendID;
        }) != friends.cend();
    }
    bool getID() const {
        return ID;
    }

public slots:
    void addFriend(Friend afriend) {
        friends.push_back(afriend);
    }

    void addGroup(Group group) {
        groups.push_back(group);
    }

private:
    long ID;
    QString name;
    QVector<Friend> friends;
    QVector<Group> groups;
};


#endif //QTWORK_USERINFO_H
