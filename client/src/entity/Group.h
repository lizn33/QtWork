//
// Created by ccx on 22-6-15.
//

#ifndef QTWORK_GROUP_H
#define QTWORK_GROUP_H

#include <QString>


class Group {

public:
    long getID() const {
        return id;
    }

    QString getName() const {
        return name;
    }

private:
    long id;
    QString name;

};

#endif //QTWORK_GROUP_H
